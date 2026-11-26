#include "cpu.h"
#include "registers.h"
#include "../cartridge/cartridge.h" // eventually this will probably get replaced

registers_struct registers;

uint8_t mock_memory_bus = 0; // TODO: replace this crap with an actual memory bus

void sm83_reset() {
	// Initial register address values
	registers.AF = 0x01B0;
	registers.BC = 0x0013;
	registers.DE = 0x00D8;
	registers.HL = 0x014D;
	registers.SP = 0xFFFE;
	registers.PC = 0x0100;
}

const sm83_instruction* sm83_fetch_cycle() {
	uint8_t opcode = cartridge_rom_data[registers.PC];
	const sm83_instruction* instruction_ptr = &instruction_set[opcode];
	return instruction_ptr;
}

bool sm83_execute_cycle(const sm83_instruction* instruction_ptr) {
	sm83_instruction instruction = *instruction_ptr;
	void* instruction_address = instruction.opcode_ptr;
	if(!instruction_address) {
		printf("Instruction at PC address %.4X (%s) points to a null pointer. \n", 
			registers.PC, instruction.opcode);
		return false;
	}
	else {
		((execute_sm83_instruction)instruction_address)();
		return true;
	}
}

void increment_pc() {
	registers.PC+=1;
}
