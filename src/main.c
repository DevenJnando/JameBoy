#include "arch/common.h"
#include "cartridge/cartridge.h"
#include "sm83/cpu.h"
#include "sm83/control.h"
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

	if(!init_core()){
		return -1;
	}

	core_loop();
	
	SDL_Quit();

	return 0;
}