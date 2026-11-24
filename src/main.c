#include "arch/common.h"
#include "cartridge/cartridge.h"
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
	
	const char* default_rom_path = "../roms/Tetris (World) (Rev 1).gb";

	if (load_cartridge_data(default_rom_path)) {
		print_cart_info();
	}

	SDL_Quit();

	return 0;
}