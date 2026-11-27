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

int16_t get_int16_from_pc() {
	int8_t address_chunk_1 = data_bus_read(registers.PC);
	increment_clock_one_tick();
	increment_pc();
	int8_t address_chunk_2 = data_bus_read(registers.PC);
	increment_clock_one_tick();
	int16_t new_address = ((int16_t)address_chunk_2 << 8 | address_chunk_1);
	return new_address;
}

uint8_t get_uint8_from_pc() {
	uint8_t address = data_bus_read(registers.PC);
	return address;
}

int8_t get_int8_from_pc() {
	int8_t address = data_bus_read(registers.PC);
	return address;
}

void unconditional_jump() {
	increment_clock_one_tick();
	increment_pc();
	uint16_t new_address = get_uint16_from_pc();
	registers.PC = new_address;
	increment_clock_one_tick();
}

void c_relative_jump_to_e(bool condition) {
	increment_clock_one_tick();
	increment_pc();
	int8_t relative_address = get_int8_from_pc();
	increment_clock_one_tick();
	increment_pc();
	if(condition) {
		registers.PC = registers.PC + relative_address;
		increment_clock_one_tick();
	}
}

void NZ_relative_jump_to_e() {
	c_relative_jump_to_e(!get_zero_flag());
}

void Z_relative_jump_to_e() {
	c_relative_jump_to_e(get_zero_flag());
}

void NC_relative_jump_to_e() {
	c_relative_jump_to_e(!get_carry_flag());
}

void C_relative_jump_to_e() {
	c_relative_jump_to_e(get_carry_flag());
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

void exclusive_or_A_to_B() {
	increment_clock_one_tick();
	exclusive_or_A_to_r(registers.B);
	increment_pc();
}

void exclusive_or_A_to_C() {
	increment_clock_one_tick();
	exclusive_or_A_to_r(registers.C);
	increment_pc();
}

void exclusive_or_A_to_D() {
	increment_clock_one_tick();
	exclusive_or_A_to_r(registers.D);
	increment_pc();
}

void exclusive_or_A_to_E() {
	increment_clock_one_tick();
	exclusive_or_A_to_r(registers.E);
	increment_pc();
}

void exclusive_or_A_to_H() {
	increment_clock_one_tick();
	exclusive_or_A_to_r(registers.H);
	increment_pc();
}

void exclusive_or_A_to_L() {
	increment_clock_one_tick();
	exclusive_or_A_to_r(registers.L);
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

void load_uint8_to_r(uint8_t* r) {
	uint8_t address_to_load = get_uint8_from_pc();
	*r = address_to_load;
	increment_pc();
}

void load_uint8_to_A() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* A_ptr = &registers.A;
	load_uint8_to_r(A_ptr);
}

void load_uint8_to_B() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* B_ptr = &registers.B;
	load_uint8_to_r(B_ptr);
}

void load_uint8_to_C() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* C_ptr = &registers.C;
	load_uint8_to_r(C_ptr);
}

void load_uint8_to_D() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* D_ptr = &registers.D;
	load_uint8_to_r(D_ptr);
}

void load_uint8_to_E() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* E_ptr = &registers.E;
	load_uint8_to_r(E_ptr);
}

void load_uint8_to_H() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* H_ptr = &registers.H;
	load_uint8_to_r(H_ptr);
}

void load_uint8_to_L() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* L_ptr = &registers.L;
	load_uint8_to_r(L_ptr);
}

void load_from_A_dec_HL() {
	increment_clock_one_tick();
	data_bus_write(registers.HL, registers.A);
	registers.HL = registers.HL-=1;
	increment_clock_one_tick();
	increment_pc();
}

void dec_uint8_from_r(uint8_t* r) {
	set_sub_flag(true);
	set_half_carry_flag(*r < 0x01);
	*r = *r-=1;
	if(*r == 0) {
		set_zero_flag(true);
	} else {
		set_zero_flag(false);
	}
}

void dec_uint8_from_A() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* A_ptr = &registers.A;
	dec_uint8_from_r(A_ptr);
}

void dec_uint8_from_B() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* B_ptr = &registers.B;
	dec_uint8_from_r(B_ptr);
}

void dec_uint8_from_C() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* C_ptr = &registers.C;
	dec_uint8_from_r(C_ptr);
}

void dec_uint8_from_D() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* D_ptr = &registers.D;
	dec_uint8_from_r(D_ptr);
}

void dec_uint8_from_E() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* E_ptr = &registers.E;
	dec_uint8_from_r(E_ptr);
}

void dec_uint8_from_H() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* H_ptr = &registers.H;
	dec_uint8_from_r(H_ptr);
}

void dec_uint8_from_L() {
	increment_clock_one_tick();
	increment_pc();
	uint8_t* L_ptr = &registers.L;
	dec_uint8_from_r(L_ptr);
}