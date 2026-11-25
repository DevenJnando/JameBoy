#include <stdint.h>
#include <stdbool.h>
#define MAX_CARTRIDGE_SIZE 0x800000

extern uint8_t cartridge_rom_data[MAX_CARTRIDGE_SIZE];

typedef struct {
	uint8_t entry_point[4];
	uint8_t nintendo_logo[48];
	uint8_t title[15];
	uint8_t cgb_flag;
	uint8_t new_licensee_code[2];
	uint8_t sgb_flag;
	uint8_t cartridge_type;
	uint8_t rom_size;
	uint8_t ram_size;
	uint8_t dest_code;
	uint8_t old_licensee_code;
	uint8_t mask_rom_version;
	uint8_t header_checksum;
	uint8_t global_checksum[2];

} cartridge_headers;

extern bool cartridge_loaded;
extern cartridge_headers* cart_header;

bool load_cartridge_data(const char* filename);
void print_cart_info();