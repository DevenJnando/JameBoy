#include "cartridge.h"
#include <stdio.h>
#include <stdlib.h>

uint8_t cartridge_rom_data[MAX_CARTRIDGE_SIZE];
bool cartridge_loaded = false;
cartridge_headers* cart_header = (cartridge_headers*)(cartridge_rom_data + 0x0100);

void print_cart_info() {
	printf("Entry points at each byte: %.2X %.2X %.2X %.2X \n", 
		cart_header->entry_point[0],
		cart_header->entry_point[1],
		cart_header->entry_point[2],
		cart_header->entry_point[3]);
	printf("Title: %s \n", cart_header->title);
	printf("CGB flag: %.2X \n", cart_header->cgb_flag);
	printf("New Licensee Code: %.2X %.2X \n", 
		cart_header->new_licensee_code[0], 
		cart_header->new_licensee_code[1]);
	printf("SGB flag: %.2X \n", cart_header->sgb_flag);
	printf("Cartridge_type: %.2X \n", cart_header->cartridge_type);
	printf("ROM size: %.2X \n", cart_header->rom_size);
	printf("RAM size: %.2X \n", cart_header->ram_size);
	printf("Destination code: %.2X \n", cart_header->dest_code);
	printf("Old Licensee Code: %.2X \n", cart_header->old_licensee_code);
	printf("Mask ROM Version: %.2X \n", cart_header->mask_rom_version);
	printf("Header checksum: %.2X \n", cart_header->header_checksum);
	printf("Global checksum: %.2X %.2X \n", 
		cart_header->global_checksum[0],
		cart_header->global_checksum[1]);

}

bool load_cartridge_data(const char* filename) {
	FILE* cart;
	cart = fopen(filename, "r");
	if(cart == NULL) {
		printf("Failed to load specified file: %s \n", filename);
		return cartridge_loaded;
	}
	fread(cartridge_rom_data, sizeof(char*), MAX_CARTRIDGE_SIZE, cart);
	fclose(cart);
	printf("Loaded catridge ROM %s with size of %li \n", filename, sizeof(cartridge_rom_data));
	cartridge_loaded = true;
	return cartridge_loaded;
}
