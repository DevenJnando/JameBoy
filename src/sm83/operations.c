#include "cpu.h"
#include "control.h"
#include "registers.h"
#include "data_bus.h"

void no_operation() {
	increment_clock_one_tick();
	increment_pc();
}

uint16_t get_uint16_from_pc() {
	uint8_t address_chunk_1 = data_bus_read(registers.PC);
	increment_clock_one_tick();
	increment_pc();
	uint8_t address_chunk_2 = data_bus_read(registers.PC);
	increment_clock_one_tick();
	uint16_t new_address = ((uint16_t)address_chunk_2 << 8) | address_chunk_1;
	return new_address;
}

void unconditional_jump() {
	increment_clock_one_tick();
	increment_pc();
	uint16_t new_address = get_uint16_from_pc();
	registers.PC = new_address;
	increment_clock_one_tick();
}

void exclusive_or_A_to_r(uint8_t r) {
	uint8_t result = registers.A ^ r;
	registers.A = result;
	if(result == 0) {
		set_zero_flag(true);
	} else {
		set_zero_flag(false);
	}
	set_sub_flag(false);
	set_half_carry_flag(false);
	set_carry_flag(false);
}

void exclusive_or_A_to_A() {
	increment_clock_one_tick();
	exclusive_or_A_to_r(registers.A);
	increment_pc();
}

void load_uint16_to_r(uint16_t* r) {
	uint16_t address_to_load = get_uint16_from_pc();
	*r = address_to_load;
	increment_pc();
}

void load_uint16_to_HL() {
	increment_clock_one_tick();
	increment_pc();
	uint16_t* HL_ptr = &registers.HL;
	load_uint16_to_r(HL_ptr);
}


