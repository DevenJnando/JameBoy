#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "instr.h"

void sm83_reset();
const sm83_instruction* sm83_fetch_cycle();
void sm83_execute_cycle(const sm83_instruction* instruction_ptr);
void increment_pc();

typedef void (*execute_sm83_instruction)();