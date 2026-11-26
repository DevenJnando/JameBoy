#include <stdint.h>
#include <stdbool.h>

extern uint32_t sm83_clock_counter;
extern bool shutdown_signal_received;

bool init_core();
void core_loop();
void shutdown_core();
void increment_clock_one_tick();