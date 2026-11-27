#include <stdint.h>
#include <stdbool.h>

void no_operation(); // Passes a single clock tick

/* 
	Unsigned 8 and 16-bit retrievals from the program counter
*/
uint16_t get_uint16_from_pc(); // Gets an unsigned 16-bit integer from the program counter
int16_t get_int16_from_pc(); // Gets a signed 16-bit integer from the program counter
uint8_t get_uint8_from_pc(); // Gets an unsigned 8-bit integer from the program counter
int8_t get_int8_from_pc(); // Gets a signed 8-bit integer from the program counter

/*
	Unconditional jump instructions
*/
void unconditional_jump(); // Jumps straight to specified address

/*
	Conditional relative jump instructions
*/
void c_relative_jump_to_e(bool condition); // Conditional jump to relative address
void NZ_relative_jump_to_e(); // Zero flag not set condition
void Z_relative_jump_to_e(); // Zero flag set condition
void NC_relative_jump_to_e(); // Carry flag not set condition
void C_relative_jump_to_e(); // Carry flag set condition

/*
	XOR instructions
*/
void exclusive_or_A_to_r(); // XOR comparison with A register to another register
void exclusive_or_A_to_A(); // XOR comparison with A register to itself - quick way of setting zero flag
void exclusive_or_A_to_B(); // XOR comparison with A register to the B register
void exclusive_or_A_to_C(); // XOR comparison with A register to the C register
void exclusive_or_A_to_D(); // XOR comparison with A register to the D register
void exclusive_or_A_to_E(); // XOR comparison with A register to the E register
void exclusive_or_A_to_H(); // XOR comparison with A register to the H register
void exclusive_or_A_to_L(); // XOR comparison with A register to the L register

/*
	8-bit load instructions
*/
void load_uint8_to_r(uint8_t* r); // Loads an unsigned 8-bit integer to some register
void load_uint8_to_A(); // Loads an unsigned 8-bit integer to the A register
void load_uint8_to_B(); // Loads an unsigned 8-bit integer to the B register
void load_uint8_to_C(); // Loads an unsigned 8-bit integer to the C register
void load_uint8_to_D(); // Loads an unsigned 8-bit integer to the D register
void load_uint8_to_E(); // Loads an unsigned 8-bit integer to the E register
void load_uint8_to_H(); // Loads an unsigned 8-bit integer to the H register
void load_uint8_to_L(); // Loads an unsigned 8-bit integer to the L register

/*
	16-bit load instructions
*/
void load_uint16_to_r(uint16_t* r); // Loads an unsigned 16-bit integer to some register
void load_uint16_to_HL(); // Loads an unsigned 16-bit integer to the HL register
void load_from_A_dec_HL(); // Writes the value from the A register to the address stored in the HL register and decrements HL register

/*
	8-bit decrement instructions
*/
void dec_uint8_from_r(uint8_t* r); // Decrements an unsigned 8-bit integer from some register
void dec_uint8_from_A(); // Decrements an unsigned 8-bit integer from the A register
void dec_uint8_from_B(); // Decrements an unsigned 8-bit integer from the B register
void dec_uint8_from_C(); // Decrements an unsigned 8-bit integer from the C register
void dec_uint8_from_D(); // Decrements an unsigned 8-bit integer from the D register
void dec_uint8_from_E(); // Decrements an unsigned 8-bit integer from the E register
void dec_uint8_from_H(); // Decrements an unsigned 8-bit integer from the H register
void dec_uint8_from_L(); // Decrements an unsigned 8-bit integer from the L register