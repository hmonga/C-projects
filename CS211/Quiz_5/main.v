/**
 * This is an autogenerated netlist code from CircuitVerse. Verilog Code can be
 * tested on https://www.edaplayground.com/ using Icarus Verilog 0.9.7. This is an
 * experimental module and some manual changes make need to be done in order for
 * this to work.
 *
 * If you have any ideas/suggestions or bug fixes, raise an issue
 * on https://github.com/CircuitVerse/CircuitVerse/issues/new/choose
 */

/*
  Element Usage Report
    Input - 2 times
    Output - 2 times
    OrGate - 1 times
    NotGate - 1 times
*/

/*
  Usage Instructions and Tips
    Labels - Ensure unique label names and avoid using verilog keywords
    Warnings - Connect all optional inputs to remove warnings
*/

// Sample Testbench Code - Uncomment to use

/*
module TestBench();

  reg A, B;

  wire A_1, B_1;

  Main DUT0(A_1, B_1, A, B);

  initial begin
    A = 0;
    B = 0;

    #15
    $display("A_1 = %b", A_1);
    $display("B_1 = %b", B_1);

    #10
    $display("A_1 = %b", A_1);
    $display("B_1 = %b", B_1);

    $finish;

  end
endmodule

*/

module Main(A_1, B_1, A, B);
  output A_1,  B_1;
  input A, B;
  wire or_0_out, not_0_out;
  assign A_1 = B;
  assign or_0_out = not_0_out | A;
  assign B_1 = or_0_out;
  assign not_0_out = ~A;
endmodule
