/*

Maximus Darby

----------------
Inspiration from Nand2mario tangnano 20k sdram but optimized
for caching.

*/


module SDRAM 
#(
    parameter FREQ  = 27000000,     // Default freq of tang nano20k
    parameter T_MRD = 4'd2,         // Mode register set latency   
    parameter T_RCD = 4'd2,         // RAS to CAS Latency
    parameter T_RP  = 4'd4,         // RAS Prechrage latency
    parameter T_CAS = 4'd2 ,        // Delay until Data appears on output
    parameter T_WR  = 4'd1,         // Delay until row can be closed follwoing a write
    parameter T_RC  = 4'd2,         // Delay until RAS can be executed again
    parameter T_BL  = 4'd8,         // Delay burst length
    parameter T_CL  = 4'd1          // delay until data is available

)
(

    input reg start, // start the SDRAM 
    input reg clk,
    input reg clke, // Enable controller
    input reg sdram_clk, // Shifted clock

    output reg CS,  // chip select
    output reg CAS, // Col to access
    output reg RAS, // Row to access
    output reg WE, // Write enable
    output reg CL , // the latency from RAS to CAS

    output reg busy, // Instruction in progress

    output reg[3:0] DQM_out, // Bits to mask 

    input write,
    input read,
    input[22:0] Address_in,
    inout[31:0] Data_bus,
    
    output reg[1:0] Bank_Bits_out, // Bank adress 
    output reg[10:0] Address_out // Input adress bus

);

// Convert the FREQ to the amount of cycles in 15us
// once this count is reached the sdram needs a refresh

localparam CYCLES_TO_REFRESH = FREQ / 1000 / 1000 * 15 ; // 15us
localparam STARTUP_WAIT = FREQ / 1000 / 1000 * 200; // 200us


localparam STARTUP      = 3'b111; // When the device boots up
localparam CONFIG       = 3'b110; //  200 ms delay
localparam IDLE         = 3'b000; // Set Mode register


// These Double down as the opcodes for read write
localparam READ         = 3'b101; // Read operations
localparam WRITE        = 3'b100; // Write operations
localparam REFRESH      = 3'b001; // Refresh operations


// auto precharge comes from A[10]
// Format -> { RAS , CAS , WE }

localparam BANK_ACTIVATE    = 3'b011;
localparam PRECHARGE        = 3'b010;
localparam AUTOREFRESH      = 3'b001;

localparam MODEREG_SET      = 3'b000;

/*
Burst,
NormalMode,
CAS->2Cycles,
Burst_Type->sequential,
Burst_Length->FULLPAGE
*/ 
localparam MODEREG_CONFIG   = 11'0 0 00 010 0 011 ;


wire [10:0]RAS_BITS     = Address_buffer[10:0];     // ROW
wire [1:0]BANK_BITS     = Address_buffer[12:11];    // BANK
wire [9:0]CAS_BITS      = Address_buffer[22:13];    // COL


// The current cycle of the FSM
// Will reset each time refresh is done

reg refresh_needed;
reg[2:0] STATE;

reg[4:0] burst_counter;
reg[15:0] cycle_counter; // Current instruction cycle
reg[15:0] refresh_counter; // refresh manager

reg [22:0]Address_buffer;   // Holds current address
reg [31:0]Data_buffer;      // Data address to write to 

assign CL = T_CL;
assign CS = 0; // Chip select is active low , allows chip to always run


// state logic here 
always @(posedge clk) begin
    cycle_counter   <= cycle_counter + 1;
    refresh_counter <= refresh_counter + 1;
    DQM_out <= 0;
end

always @(posedge clk) begin
    
    // reset pin to start the sdram
    if(reset) begin
        cycle_counter <= 0;
        refresh_needed <= 0;
        STATE <= STARTUP;        
    end


    casex ( { STATE , cycle_counter} ) 
        
        { STARTUP , 4'bxxxx } : begin
            // wait 200us
            if( cycle_counter >= STARTUP_WAIT ) begin
                STATE <= CONFIG;
                refresh_timer <= 0;
                refresh_needed <= 0;
                cycle_counter <= 0;
            end
        end 
        
        // If startup the cycle is irrelevent
        { CONFIG , 4'b0000 } : begin
            // Precharge
            A[10] <= 1'b1;
            { RAS , CAS , WE} <= PRECHARGE; 
        end
        // Refresh 1 and 2
        { CONFIG , T_RP }, 
        { CONFIG , T_RP + T_RC} : begin
            //Refresh
            {RAS , CAS , WE} <= AUTOREFRESH;

        end

        // Set the mode register
        { CONFIG , T_RP + T_RC + T_RC} : begin
            
            { RAS , CAS , WE} <= MODEREG_SET;
            A <= MODEREG_CONFIG;
        end

        // Set to the correct state
        { CONFIG , T_RP + T_RC + T_RC + T_MRD } : begin
            STATE <= IDLE;
            busy <= 0;
        end


        /**/
        { IDLE , 15'bx } : if ( refresh ) begin
            STATE <= REFRESH;
            { RAS , CAS , WE} <= REFRESH;
            cycle_counter <= 1;
            busy <= 1;

        end 
        else if( read | write) begin

        {RAS , CAS , WE} <= BANK_ACTIVATE;
        Bank_Address_out <= BANK_BITS;
        Address_out <=  RAS_BITS;
        STATE <= read ? READ : WRITE;

        Address_buffer <= Address_in;

        // write then load data to write
        if( write ) Data_buffer <= Data_bus;
        // reset the cycle counter for the next operation
        cycle_counter <= 1;
        busy <= 1; // Instruction start
        burst_counter <= 0;

        end


        { READ , T_RCD } : begin

            {RAS , CAS , WE} <= READ; // read instruction
            Address_out[10:0] <= {1 , CAS_ADDR}; // Precharge and CAS

        end

        { READ , T_RCD + T_CAS + T_BL + T_RP} begin
            STATE <= IDLE;
            cycle_counter <= 0;
            busy <= 0;
        end 


        {WRITE , T_RCD } : begin
            
            { RAS , CAS , WE} <= WRITE;
            Address_out[10:0] <= { 1'b1 , CAS_ADDR};

        end

        {WRITE , T_RCD + T_WR + T_BL + T_RP}: begin
            STATE <= IDLE;
            cycle_counter <= 0;
            busy <= 0;
        end

        {REFRESH , T_RC } : begin
            STATE <= IDLE;
            busy <= 0;
            refresh_counter <= refresh_counter - CYCLES_TO_REFRESH;
            refresh_needed <= 0;
        end
            
                


    endcase
    
    refresh_needed <= refresh_counter >= CYCLES_TO_REFRESH; 

end

endmodule;