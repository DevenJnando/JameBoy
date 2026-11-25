#include <stdint.h>

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
