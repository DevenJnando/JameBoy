#include <stdint.h>
#include <stdbool.h>
#ifndef ZERO_FLAG
#define ZERO_FLAG 0x80
#endif
#ifndef SUB_FLAG
#define SUB_FLAG 0x70
#endif
#ifndef HALF_CARRY_FLAG
#define HALF_CARRY_FLAG 0x60
#endif
#ifndef CARRY_FLAG
#define CARRY_FLAG 0x50
#endif

typedef struct {
	uint16_t PC; // program counter
	uint16_t SP; // stack pointer
	union {
		struct {
			uint8_t A; // accumulator
			uint8_t F; // flags
			uint16_t AF;
		};
	};
	// special purpose 8-bit registers
	union {
		struct {
			uint8_t B;
			uint8_t C;
			uint16_t BC;
		};
	};
	union {
		struct {
			uint8_t D;
			uint8_t E;
			uint16_t DE;
		};
	};
	union {
		struct {
			uint8_t H;
			uint8_t L;
			uint16_t HL;
		};
	};
	uint8_t IR; // interrupt register
	uint8_t IE; // interrupt enable
} registers_struct;

extern registers_struct registers;

void increment_pc();
bool get_zero_flag();
void set_zero_flag(bool value);
bool get_sub_flag();
void set_sub_flag(bool value);
bool get_half_carry_flag();
void set_half_carry_flag(bool value);
bool get_carry_flag();
void set_carry_flag(bool value);