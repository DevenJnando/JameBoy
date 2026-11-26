#include "registers.h"

void increment_pc() {
	registers.PC+=1;
}

bool get_zero_flag() {
	if(registers.F & ZERO_FLAG) {
		return true;
	} else {
		return false;
	}
}

void set_zero_flag(bool value) {
	if(value) {
		registers.F |= ZERO_FLAG; // sets zero flag to true
	} else {
		registers.F &= ~ZERO_FLAG; // sets zero flag to false
	}
}

bool get_sub_flag() {
	if(registers.F & SUB_FLAG) {
		return true;
	} else {
		return false;
	}
}

void set_sub_flag(bool value) {
	if(value) {
		registers.F |= SUB_FLAG;
	} else {
		registers.F &= ~SUB_FLAG;
	}
}

bool get_half_carry_flag() {
	if(registers.F & HALF_CARRY_FLAG) {
		return true;
	} else {
		return false;
	}
}

void set_half_carry_flag(bool value) {
	if(value) {
		registers.F |= HALF_CARRY_FLAG;
	} else {
		registers.F &= ~HALF_CARRY_FLAG;
	}
}

bool get_carry_flag() {
	if(registers.F & CARRY_FLAG) {
		return true;
	} else {
		return false;
	}
}

void set_carry_flag(bool value) {
	if(value) {
		registers.F |= CARRY_FLAG;
	} else {
		registers.F &= ~CARRY_FLAG;
	}
}
