import os
import subprocess
import argparse

# Updated Testbench Template
TESTBENCH_TEMPLATE = """
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
"""

def write_testbench():
    """Write the updated testbench to a file."""
    with open("testbench.v", "w") as f:
        f.write(TESTBENCH_TEMPLATE)

def run_verilog_simulation(verilog_file):
    """Run the Verilog simulation using Icarus Verilog."""
    try:
        subprocess.run(["iverilog", "-o", "simulation", verilog_file, "testbench.v"], check=True)
        result = subprocess.run(["vvp", "simulation"], capture_output=True, text=True)
        return result.stdout
    except subprocess.CalledProcessError as e:
        print(f"Error running Verilog simulation: {e}")
        return None

def parse_simulation_output(output):
    """Parse the simulation output to calculate the score."""
    score = 5  # 5 points for submission
    passed_tests = 0

    # Updated expected output checks
    if "Error: Test case 1 failed!" not in output:
        passed_tests += 1  # 00 -> 01 (A_1 = 0, B_1 = 1)
    if "Error: Test case 2 failed!" not in output:
        passed_tests += 1  # 01 -> 11 (A_1 = 1, B_1 = 1)
    if "Error: Test case 3 failed!" not in output:
        passed_tests += 1  # 10 -> 01 (A_1 = 0, B_1 = 1)
    if "Error: Test case 4 failed!" not in output:
        passed_tests += 1  # 11 -> 11 (A_1 = 1, B_1 = 1)

    score += passed_tests * 1.25
    return score, output

def main():
    parser = argparse.ArgumentParser(description="Test a Verilog file.")
    parser.add_argument("verilog_file", help="Path to the Verilog file to test.")
    args = parser.parse_args()

    write_testbench()
    simulation_output = run_verilog_simulation(args.verilog_file)

    if simulation_output:
        score, output = parse_simulation_output(simulation_output)
        print("\n========================================")
        print(f"Final Score: {score}/10")
        print("========================================\n")
        print("Simulation output:\n")
        print(output)
        print("\n========================================")

if __name__ == "__main__":
    main()
