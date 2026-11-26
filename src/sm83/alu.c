#include "cpu.h"
#include "control.h"
#include "registers.h"
#include "../cartridge/cartridge.h"

void no_operation() {
	increment_clock_one_tick();
	increment_pc();
}

void unconditional_jump() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t address_chunk_1 = cartridge_rom_data[registers.PC];
	increment_clock_one_tick();
	increment_pc();
	uint8_t address_chunk_2 = cartridge_rom_data[registers.PC];
	increment_clock_one_tick();
	uint16_t new_address = ((uint16_t)address_chunk_2 << 8) | address_chunk_1;
	registers.PC = new_address;
	increment_clock_one_tick();
}
