#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "instr.h"

void sm83_reset();
const sm83_instruction* sm83_fetch_cycle();
bool sm83_execute_cycle(const sm83_instruction* instruction_ptr);
void increment_pc();

typedef void (*execute_sm83_instruction)();
typedef void (*execute_sm83_instruction_uint8_one_arg)(uint8_t* arg1);
typedef void (*execute_sm83_instruction_uint8_two_args)(uint8_t* arg1, uint8_t* arg2);
typedef void (*execute_sm83_instruction_uint16_one_arg)(uint16_t* arg1);
typedef void (*execute_sm83_instruction_uint16_two_args)(uint16_t* arg1, uint16_t* arg2);