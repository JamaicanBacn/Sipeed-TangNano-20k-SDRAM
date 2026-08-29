


module SDRAMTop(

input wire sys_clk,
input wire s1,


output O_sdram_clk,
output O_sdram_cke,
output O_sdram_cs_n,            // chip select
output O_sdram_cas_n,           // columns address select
output O_sdram_ras_n,           // row address select
output O_sdram_wen_n,           // write enable
inout [31:0] IO_sdram_dq,       // 32 bit bidirectional data bus
output [10:0] O_sdram_addr,     // 11 bit multiplexed address bus
output [1:0] O_sdram_ba,        // two banks
output [3:0] O_sdram_dqm,       // Data mask




);



endmodule
