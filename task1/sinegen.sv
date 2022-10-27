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
    output logic [D_WIDTH-1:0] dout
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
    // i.e. module input count is connected to address
);

rom sineRom (
    .clk(clk),
    .addr(address),
    .dout(dout)
);

endmodule
