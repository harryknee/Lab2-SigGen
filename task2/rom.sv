// 256x8 ROM (256 addresses, each can store 8 bits of data)
module rom #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8
)(
    input logic clk,
    input logic [ADDRESS_WIDTH-1:0] addr,
    input logic [ADDRESS_WIDTH-1:0] addrDiff,
    output logic [DATA_WIDTH-1:0] dout1,
    output logic [DATA_WIDTH-1:0] dout2
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];
// a rom_array is a list of [8] bit, with a total of [256] items

initial begin
        $display("Loading rom.");
        $readmemh("sinerom.mem", rom_array); // load hex code into rom
end;

always_ff @(posedge clk) begin
    // output is synchronous
    dout1 <= rom_array [addr];
    dout2 <= rom_array [addr + addrDiff];
end
endmodule
