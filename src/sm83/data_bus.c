#include "../cartridge/cartridge.h"

uint8_t data_bus_read(uint16_t address) {
	return cartridge_rom_data[address];
}

void data_bus_write(uint16_t address, uint8_t value) {
	// TODO: make it work real good.
}
