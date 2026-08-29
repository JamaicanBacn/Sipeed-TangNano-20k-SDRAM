


module SDRAM 
#(
    parameter FREQ = 27,000,000;  // Default freq of tang nano20k
    parameter T_MRD; // Mode register set latency   
    parameter T_RCD; // RAS to CAS Latency
    parameter T_RP;   // RAS Prechrage latency
    parameter T_CAS; // Delay until Data appears on output
    parameter T_WR;  // Delay until row can be closed follwoing a write
    parameter T_RC; // Delay until RAS can be executed again

)
(

    input wire start, // start the SDRAM 
    input wire clk,
    input wire clke, // Enable controller
    input wire sdram_clk, // Shifted clock

    input wire CAS, // Col to access
    input wire RAS, // Row to access
    input wire WE, // Write enable
    input wire CL, // the latency from RAS to CAS

    input wire[3:0] DQM, // Bits to mask 

    input write,
    input read,
    
    input wire[1:0] BA, // Bank to adress
    input wire[10:0] A // Input adress bus




);


// Convert the FREQ to the amount of cycles in 15us
// once this count is reached the sdram needs a refresh

localparam CYCLES_TO_REFRESH = FREQ / 1000 / 1000 * 15 ;


localparam INIT     = 3'b000; // When the device boots up
localparam STARTUP  = 3'b001; // Setup the device specs
localparam READ     = 3'b010; // Read operations
localparam WRITE    = 3'b011; // Write operations
localparam REFRESH  = 3'b100; // Refresh operations

reg[2:0] STATE;               // Current FSM state
reg[15:0] refresh_timer;      // Refresh indicator 



always @(posedge clk) begin

end

/*

Notes:
    Either SDRAM or FPGA can drive the data line.
    if both try at the same time a short occurs.
    When neither are using the line us HIGH Z to cut inputs.

    ** WILL DESTORY SDRAM IF IMPLEMENTED WRONG **

    RAS : HIGH Z

    CAS - WRITE : FPGA DRIVES
    CAS - READ  : DRAM DRIVES 

Init:
    Precharge and wait 200us
    Refresh
    Refresh
    Set Controller Mode

READ:
    Load RAS command with precharge and Row addr
    Load CAS command with col addr after TRCD
    2 cycles later data is availible.




WRITE:
    Load Ras command with precharge and Row addr
    Load Cas command with WE and col addr after TRCD
    Data will the be placed into the SDRA
REFRESH:
    every 15us check if a command is running.
    If not send refresh command.
    Wait refresh time and return to exec.
    If a command is running wait until done and refresh.




*/



endmodule;