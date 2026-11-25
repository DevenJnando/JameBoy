#include "arch/common.h"
#include "cartridge/cartridge.h"
#include "sm83/cpu.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#define SDL_MAIN_HANDLED

int SDLCALL jameboy_run(int argc, char** argv);

int main(int argc, char** argv) {
	return SDL_RunApp(argc, argv, jameboy_run, NULL);
}

int SDLCALL jameboy_run(int argc, char** argv) {
	if(!SDL_Init(SDL_INIT_VIDEO)) {
		return -1;
	}

	sm83_reset();
	
	const char* default_rom_path = "../roms/Tetris (World) (Rev 1).gb";
	cartridge_loaded = load_cartridge_data(default_rom_path);

	if(!cartridge_loaded) {
		printf("No cartridge loaded. Cannot perform fetch cycle. \n");
		exit(1);
	}

	print_cart_info();
	const sm83_instruction* instruction_ptr = sm83_fetch_cycle();
	sm83_execute_cycle(instruction_ptr);
	
	SDL_Quit();

	return 0;
}