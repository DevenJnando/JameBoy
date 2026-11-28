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
void exclusive_or_A_to_r(uint8_t* r); // XOR comparison with A register to another register

/*
	8-bit load instructions
*/
void load_uint8_to_r(uint8_t* r); // Loads an unsigned 8-bit integer to some register
void load_r_to_r_prime(uint8_t* r, uint8_t* r_prime); // Loads the value in some register to another register

/*
	16-bit load instructions
*/
void load_uint16_to_r(uint16_t* r); // Loads an unsigned 16-bit integer to some register
void load_from_A_dec_HL(); // Writes the value from the A register to the address stored in the HL register and decrements HL register

/*
	8-bit decrement instructions
*/
void dec_uint8_from_r(uint8_t* r); // Decrements an unsigned 8-bit integer from some register

/*
	8-bit increment instructions
*/
void inc_uint8_from_r(uint8_t* r); // Increments an unsigned 8-bit integer from some register