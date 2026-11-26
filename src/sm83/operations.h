#include <stdint.h>

void no_operation();
uint16_t get_uint16_from_pc();
void unconditional_jump();
void exclusive_or_A_to_r();
void exclusive_or_A_to_A();
void load_uint16_to_r(uint16_t* r);
void load_uint16_to_HL();