
`timescale 1ns / 1ps

module TestBench();
    // Inputs
    reg A;
    reg B;

    // Outputs
    wire A_1;
    wire B_1;

    // Instantiate the Unit Under Test (UUT)
    Main DUT0(A_1, B_1, A, B);

    // Testbench logic
    initial begin
        // Test all possible input combinations
        $display("Testing all input combinations...");
        $display("A B | A_1 B_1 | Expected A_1 B_1");

        // Test case 1: A = 0, B = 0 -> Expected: A_1 = 0, B_1 = 1
        A = 0; B = 0;
        #10;
        $display("%b %b |  %b   %b  | 0 1", A, B, A_1, B_1);
        if (A_1 !== 0 || B_1 !== 1) $display("Error: Test case 1 failed!");

        // Test case 2: A = 0, B = 1 -> Expected: A_1 = 1, B_1 = 1
        A = 0; B = 1;
        #10;
        $display("%b %b |  %b   %b  | 1 1", A, B, A_1, B_1);
        if (A_1 !== 1 || B_1 !== 1) $display("Error: Test case 2 failed!");

        // Test case 3: A = 1, B = 0 -> Expected: A_1 = 0, B_1 = 1
        A = 1; B = 0;
        #10;
        $display("%b %b |  %b   %b  | 0 1", A, B, A_1, B_1);
        if (A_1 !== 0 || B_1 !== 1) $display("Error: Test case 3 failed!");

        // Test case 4: A = 1, B = 1 -> Expected: A_1 = 1, B_1 = 1
        A = 1; B = 1;
        #10;
        $display("%b %b |  %b   %b  | 1 1", A, B, A_1, B_1);
        if (A_1 !== 1 || B_1 !== 1) $display("Error: Test case 4 failed!");

        // End of test
        $display("Testing complete.");
        $finish;
    end
endmodule
