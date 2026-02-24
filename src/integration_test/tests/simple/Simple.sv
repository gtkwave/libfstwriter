// SPDX-FileCopyrightText: 2025 Yu-Sheng Lin <johnjohnlys@gmail.com>
// SPDX-License-Identifier: MIT
module Simple (
  // input
  input clk,
  input rst_n
);

// define a 2b enum named CounterAdd
typedef enum logic [1:0] {
  ZERO = 2'b00,
  ONE = 2'b01,
  TWO = 2'b10,
  THREE = 2'b11
} counter_add_e;

counter_add_e counter_add_enum_version;
assign counter_add_enum_version = counter_add_e'(counter_add);

logic [1:0] counter_add;
always_ff @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    counter_add <= 2'b00;
  end else begin
    counter_add <= counter_add + 2'b01;
  end
end

logic [126:0] counter_shift;
always_ff @(posedge clk or negedge rst_n) begin
  if (!rst_n) begin
    counter_shift <= 127'b0;
  end else begin
    counter_shift <= {counter_shift[124:0], 2'b11};
  end
end

endmodule
