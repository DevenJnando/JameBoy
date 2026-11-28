#include "cpu.h"
#include "registers.h"
#include "data_bus.h"

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
	uint8_t opcode = data_bus_read(registers.PC);
	const sm83_instruction* instruction_ptr = &instruction_set[opcode];
	return instruction_ptr;
}

bool sm83_execute_cycle(const sm83_instruction* instruction_ptr) {
	sm83_instruction instruction = *instruction_ptr;
	void* instruction_address = instruction.opcode_ptr;
	if(!instruction_address) {
		printf("Instruction %.2X at PC address %.4X (%s) points to a null pointer. \n", 
			instruction.opcode_address, registers.PC, instruction.opcode);
		return false;
	}
	else {
		if(instruction.no_of_uint8_args != 0){
			uint8_t* func_args[sizeof(uint8_t*) * instruction.no_of_uint8_args];
			for(int i = 0; i < instruction.no_of_uint8_args; i++) {
				func_args[i] = instruction.uint8_args[i];
			}
			switch(instruction.no_of_uint8_args) {
				case 1:
					((execute_sm83_instruction_uint8_one_arg)instruction_address)(func_args[0]);
					return true;
					break;
				case 2:
					((execute_sm83_instruction_uint8_two_args)instruction_address)(func_args[0], func_args[1]);
					return true;
					break;
				default:
					printf("Incompatible number of arguments provided. Max is 2, have %d \n", instruction.no_of_uint8_args);
					break;
			}

		} else if(instruction.no_of_uint16_args != 0){
			uint16_t* func_args[sizeof(uint16_t*) * instruction.no_of_uint16_args];
			for(int i = 0; i < instruction.no_of_uint16_args; i++) {
				func_args[i] = instruction.uint16_args[i];
			}
			switch(instruction.no_of_uint16_args) {
				case 1:
					((execute_sm83_instruction_uint16_one_arg)instruction_address)(func_args[0]);
					return true;
					break;
				case 2:
					((execute_sm83_instruction_uint16_two_args)instruction_address)(func_args[0], func_args[1]);
					return true;
					break;
				default:
					printf("Incompatible number of arguments provided. Max is 2, have %d \n", instruction.no_of_uint16_args);
					break;
			}

		} else{
			((execute_sm83_instruction)instruction_address)();
			return true;
		}
	}
}
