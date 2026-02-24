// SPDX-FileCopyrightText: 2025 Yoda Lee <lc85301@gmail.com>
// SPDX-License-Identifier: MIT
parameter MOD_WIDTH = 256;
parameter INT_WIDTH = 32;

typedef logic [MOD_WIDTH-1:0] KeyType;

typedef logic [INT_WIDTH-1:0] IntType;

typedef struct packed {
  IntType power;
  KeyType modulus;
} TwoPowerIn;
typedef KeyType TwoPowerOut;

typedef struct packed {
  KeyType a;
  KeyType b;
  KeyType modulus;
} MontgomeryIn;
typedef KeyType MontgomeryOut;

typedef struct packed {
  KeyType base;
  KeyType msg;
  KeyType key;
  KeyType modulus;
} RSAMontModIn;
typedef KeyType RSAMontModOut;

typedef struct packed {
  KeyType msg;
  KeyType key;
  KeyType modulus;
} RSAModIn;
typedef KeyType RSAModOut;


module Testbench (
    input clk,
    input rst_n
);

// Input signals
logic i_valid;
logic i_ready;
RSAModIn i_in;

// Output signals
logic o_valid;
logic o_ready;
logic [255:0] o_out; // 256-bit output data
logic[255:0] golden_out = 256'h0D41B183313D306ADCA09126F3FED6CDEC7DCDCE49DB5C85CB2A37F08C0F2E31;

// Testbench logic
initial begin
  // Initialize signals
  i_valid = 0;
  o_ready = 1;
  i_in = 'h0;

  @(posedge rst_n);

  // Feed test data
  @(posedge clk);
  i_valid = 1;
  i_in.msg = 256'h412820616369726641206874756F53202C48544542415A494C452054524F50;
  i_in.key = 256'h10001;
  i_in.modulus = 256'hE07122F2A4A9E81141ADE518A2CD7574DCB67060B005E24665EF532E0CCA73E1;
  @(posedge clk);
  i_valid = 0;

  // Wait for output valid
  wait(o_valid);
  $display("Output data: %h", o_out);

  // Compare with golden data
  if (o_out === golden_out) begin
      $display("Test Passed!");
  end else begin
      $display("Test Failed! Expected: %h, Got: %h", golden_out, o_out);
  end
end

// Instantiate the RSA module
RSA i_rsa (
  .clk(clk),
  .rst_n(rst_n),
  .i_valid(i_valid),
  .i_ready(i_ready),
  .i_in(i_in),
  .o_valid(o_valid),
  .o_ready(o_ready),
  .o_out(o_out)
);

endmodule
