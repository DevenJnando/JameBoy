#include <stdint.h>
#include "control.h"
#include "../cartridge/cartridge.h"
#include "cpu.h"

uint32_t sm83_clock_counter = 0;
bool shutdown_signal_received = false;

bool init_core() {
	const char* default_rom_path = "../roms/Tetris (World) (Rev 1).gb";
	cartridge_loaded = load_cartridge_data(default_rom_path);

	if(!cartridge_loaded) {
		printf("No cartridge loaded. Cannot perform fetch cycle. \n");
		return false;
	}

	sm83_reset();
	print_cart_info();
	return true;
}

void core_loop() {
	// initial fetch
	const sm83_instruction* instruction_ptr = sm83_fetch_cycle();
	while(!shutdown_signal_received) {
		if(!sm83_execute_cycle(instruction_ptr)) {
			shutdown_signal_received = true;
		}
		instruction_ptr = sm83_fetch_cycle();
		// fetch comes after execute to emulate the fetch/execute overlap of the sm83 chip
	}
	
}

void shutdown_core() {

}

void increment_clock_one_tick() {
	// A functional CPU cycle is 1MHz whereas the operating frequency is 4MHz, therefore one tick is 4 clock cycles.
	sm83_clock_counter += 4;
}
