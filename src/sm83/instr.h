#include <stdint.h>

typedef struct {
	uint8_t opcode_address;
	char* opcode;
	uint8_t instruction_length;
	void* opcode_ptr;

} sm83_instruction;

extern const sm83_instruction instruction_set[256];
