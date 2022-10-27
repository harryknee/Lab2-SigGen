// top level combining counter and rom
module sinegen #(
    parameter   A_WIDTH = 8,
                D_WIDTH = 8
)(
    // interface signals
    input  logic clk,
    input  logic rst,
    input  logic en,
    input  logic [D_WIDTH-1:0] incr, // incremenet for addr counter
    input  logic [D_WIDTH-1:0] phaseDiff,
    output logic [D_WIDTH-1:0] dout1,
    output logic [D_WIDTH-1:0] dout2
);

logic [A_WIDTH-1:0] address;

// instantiate counter module
counter addrCounter (
    .clk(clk),
    .rst(rst),
    .en(en),
    .incr(incr),

    .count(address)
    // .{internal name}({external name})
    // internal signal takes the value of external signal
    // i.e. module internal {count} is an output, which is directed to external {address}
    // i.e. module internal {incr} is an input, which is taken from external {incr}
);

rom sineRom (
    .clk(clk),
    .addr(address),
    .addrDiff(phaseDiff),

    .dout1(dout1),
    .dout2(dout2)
);

endmodule
