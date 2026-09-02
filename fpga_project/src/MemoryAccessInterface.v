

module MemoryAccessInterface
( // determine type : SB , SH , SW ect.
    input wire[31:0] Data_in,
    input wire[22:0] Address_in,
    
    input wire[31:0] Instruction_in,

    output wire[31:0] Data_out, // 
    
);

localparam Store = 7'b0100011;
localparam Load  = 7'b0000011;

localparam Half_mask = 4'b1100;
localparam Byte_mask = 4'b1110;
localparam Word_mask = 4'b0000;

reg[3:0] mask;

wire opcode[6:0]    = Instruction_in[6:0];
wire funct3[2:0]    = Instruction_in[14:12];

always(*) begin
    
    case( {opcode , funct3} ) begin
        
        { Store , 4'b0 } : mask <= Byte_mask; 
        { Store , 4'b1 } : mask <= Half_mask; 
        { Store , 4'b2 } : mask <= Word_mask;

        { Load  , 4'b0 } : mask <= Byte_mask; 
        { Load  , 4'b1 } : mask <= Half_mask;
        { Load  , 4'b2 } : mask <= Word_mask;

    endcase
end

assign Data_out =   (mask == Word_mask) ? Data_in :
                    (mask == Half_mask) ? { 16{0} , Data_in[15:0]} :
                    (mask == Byte_mask) ? { 24{0} , Data_in[7:0] } ;


endmodule



module SDRAMTop(

input wire sys_clk,
input wire[22:0] Address_in,
input reg[255:0] CacheLine_in,
input wire[31:0] Instruction_in,

input wire read,
input wire write,
input wire clke,
output wire busy,
input wire reset,


output O_sdram_clk,
output O_sdram_cke,
output O_sdram_cs_n,            // chip select
output O_sdram_cas_n,           // columns address select
output O_sdram_ras_n,           // row address select
output O_sdram_wen_n,           // write enable
inout [31:0] IO_sdram_dq,       // 32 bit bidirectional data bus
output [10:0] O_sdram_addr,     // 11 bit multiplexed address bus
output [1:0] O_sdram_ba,        // four banks
output [3:0] O_sdram_dqm,       // Data mask

output reg[255:0] CacheLine_out

);


assign O_sdram_cke = clke;
assign O_sdram_clk = clk_sdram;
assign O_sdram_dqm = 4'b0000; // cache will handle this

reg [31:0]Read_data;
reg ReadReady;
reg WriteReady;
reg [5:0] BurstCounter;

reg[31:0] Unmasked_data;
reg[31:0] Data_to_sdram;

Gowin_rPLL pll(
    .clkout(clk),           // Main clock
    .clkoutp(clk_sdram),    // Phase shifted clock for SDRAM
    .clkin(sys_clk)         // 27Mhz system clock
);

MemoryAccessInterface MAI(
    .Data_in(Unmasked_data),
    .Address_in(Address_in),
    .Instruction_in(Instruction_in), // not used in this context

    .Data_out(Data_to_sdram) // Data to be written to SDRAM,
);

SDRAM RAM(
    .reset(reset),
    .clk(clk_sdram),
    .write(write),
    .read(read),

    .Address_in(Address_in),
    .Data_in(Data_to_sdram),

    .busy(busy),

    .CS(O_sdram_cs_n),
    .CAS(O_sdram_cas_n),
    .RAS(O_sdram_ras_n),
    .WE(O_sdram_wen_n),

    .Data_bus(IO_sdram_dq),
    .Address_out(O_sdram_addr),
    .Bank_Bits_out(O_sdram_ba),

    .ReadReady(ReadReady),
    .WriteReady(WriteReady),
    .Read_data(Read_data)

);

always @(posedge clk_sdram ) begin
    if(ReadReady && BurstCounter < 8) begin
        CacheLine_out[ 32 * (BurstCounter + 1) -1 : 32 * BurstCounter] <= Read_data; 
        BurstCounter <= BurstCounter + 1;
    end
    else if( WriteReady && BurstCounter < 8 ) begin
        Unmasked_data <= CacheLine_in[ 32 * (BurstCounter + 1) -1 : 32 * BurstCounter];
        BurstCounter <= BurstCounter + 1; 
    end
    
    if( ~busy ) begin
        BurstCounter <= 0;
    end
end


endmodule
