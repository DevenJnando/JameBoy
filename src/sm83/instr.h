#include <stdint.h>

typedef struct {
	char* opcode;
	uint8_t instruction_length;
	void* opcode_ptr;

} sm83_instruction;

extern const sm83_instruction instruction_set[256];
