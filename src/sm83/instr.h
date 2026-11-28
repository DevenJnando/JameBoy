#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint8_t opcode_address;
	char* opcode;
	uint8_t instruction_length;
	void* opcode_ptr;
	int no_of_uint8_args;
	int no_of_uint16_args;
	uint8_t* uint8_args[2];
	uint16_t* uint16_args[2];

} sm83_instruction;

extern const sm83_instruction instruction_set[256];
