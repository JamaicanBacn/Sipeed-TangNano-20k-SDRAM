/*

Maximus Darby

----------------
Please Read;
    Design was heavily inspired from Nand2mario's SDRAM
    Several design choices were inspired and their github is linked.

*/

`timescale 1ns/1ns 


module SDRAM 
#(
    parameter FREQ  = 27000000,     // Default freq of tang nano20k
    parameter T_MRD = 32'd2,         // Mode register set latency   
    parameter T_RCD = 32'd1,         // RAS to CAS Latency
    parameter T_RP  = 32'd1,         // RAS Prechrage latency
    parameter T_CAS = 32'd2 ,        // Delay until Data appears on output
    parameter T_WR  = 32'd2,         // Delay until row can be closed follwoing a write
    parameter T_RC  = 32'd4,         // Delay until RAS can be executed again
    parameter T_BL  = 32'd8,         // Delay burst length
    parameter T_CL  = 32'd1          // delay until data is available

)
(

    input reg reset, // start the SDRAM 
    input reg clk,
    input reg clke, // Enable controller

    output wire CS,  // chip select
    output reg CAS, // Col to access
    output reg RAS, // Row to access
    output reg WE, // Write enable

    output reg busy, // Instruction in progress

    output reg[3:0] DQM_out, // Bits to mask 

    input write,
    input read,
    input[22:0] Address_in,

    inout[31:0] Data_bus,
    
    output reg[1:0] Bank_Bits_out, // Bank adress 
    output reg[10:0] Address_ou, // Input adress bus

    output reg[31:0] Read_data

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
localparam MODEREG_CONFIG   = 11'b00000100011 ;

localparam HIGHZ        = { 32{1'bz}};
localparam DONTCARE     = { 32{1'b?}};

wire [10:0]RAS_BITS     = Address_buffer[10:0];     // ROW
wire [1:0]BANK_BITS     = Address_buffer[12:11];    // BANK
wire [9:0]CAS_BITS      = Address_buffer[22:13];    // COL


// The current cycle of the FSM
// Will reset each time refresh is done

reg startRefreshCount;

reg refresh_needed;
reg[2:0] STATE;

reg[4:0] burst_counter;
reg[31:0] cycle_counter; // Current instruction cycle
reg[31:0] refresh_counter; // refresh manager

reg [22:0]Address_buffer;   // Holds current address
reg [31:0]Data_buffer;      // Data address to write to 
reg output_enable;

assign CS = 0; // Chip select is active low , allows chip to always run

assign Data_bus = output_enable ? Data_buffer : HIGHZ; 

// state logic here 
always @(posedge clk) begin
    cycle_counter   <= cycle_counter + 1;

    if( startRefreshCount) refresh_counter <= refresh_counter + 1;
    
    DQM_out <= 0;

    if(reset) begin
        cycle_counter <= 0;
        startRefreshCount <= 0;
        burst_counter <= 0;
        STATE <= STARTUP; 
        output_enable <= 0;       
    end


end

always @(posedge clk) begin
    
    
    casez ( { STATE , cycle_counter} ) 
        
        { STARTUP , DONTCARE } : begin
            // wait 200us
            if( cycle_counter >= STARTUP_WAIT ) begin
                STATE <= CONFIG;
                refresh_counter <= 0;
                refresh_needed <= 0;
                cycle_counter <= 0;
            end

        end 
        
        { CONFIG , 32'b0 } : begin
            // Precharge
            Address_out[10] <= 1'b1;
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
            Address_out <= MODEREG_CONFIG;
        end

        // Set to the correct state
        { CONFIG , T_RP + T_RC + T_RC + T_MRD } : begin
            STATE <= IDLE;
            busy <= 0;
            startRefreshCount <= 1;
            cycle_counter <= 0;
        end


        /**/
        { IDLE , DONTCARE } : if ( refresh_needed ) begin
            STATE <= REFRESH;
            { RAS , CAS , WE} <= REFRESH;
            cycle_counter <= 1;
            busy <= 1;

        end 
        else if( read | write) begin

        {RAS , CAS , WE} <= BANK_ACTIVATE;
        Bank_Bits_out <= BANK_BITS;
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
            Address_out[10:0] <= {1'b1 , CAS_BITS}; // Precharge and CAS

        end
        { READ , T_RCD + T_CAS + T_BL + T_RP} : begin
            STATE <= IDLE;
            cycle_counter <= 0;
            busy <= 0;
            burst_counter <= 0;
            output_enable <= 0;
        end 
        { READ , HIGHZ } if( cycle_counter >= T_RCD + T_CAS) begin

            if( burst_counter < T_BL ) begin
                Read_data <= Data_bus;
                output_enable <=  0;
                burst_counter <= burst_counter + 1;  
            end
        end 
            



        {WRITE , T_RCD } : begin
            
            { RAS , CAS , WE} <= WRITE;
            Address_out[10:0] <= { 1'b1 , CAS_BITS};

        end
        {WRITE , T_RCD + T_BL + T_RP}: begin
            STATE <= IDLE;
            cycle_counter <= 0;
            busy <= 0;
            burst_counter <= 0;
            output_enable <= 0;
        end
        {WRITE , HIGHZ} : begin

                burst_counter <= burst_counter + 1;
                if( burst_counter <= T_BL) begin
                    output_enable <= 1'b1;
                end   
        end

        {REFRESH , T_RC } : begin
            STATE <= IDLE;
            busy <= 0;
            refresh_counter <= refresh_counter - CYCLES_TO_REFRESH;
            refresh_needed <= 0;
        end


        // Data_bus driver
         
                
    endcase
    
    refresh_needed <= (refresh_counter >= CYCLES_TO_REFRESH); 

end

endmodule;