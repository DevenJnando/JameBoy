#include <stddef.h>
#include "instr.h"
#include "operations.h"
#include "registers.h"

const sm83_instruction instruction_set[256] = {
	{0x00, "NOP", 1, no_operation, 0, 0, {}, {}}, //0x00
	{0x01, "LD BC,nn", 3, NULL, 0, 0, {}, {}}, //0x01
	{0x02, "LD (BC),A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x02
	{0x03, "INC BC", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x03
	{0x04, "INC B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x04
	{0x05, "DEC B", 1, dec_uint8_from_r, 1, 0, {&registers.B}, {NULL}}, //0x05
	{0x06, "LD B,n", 2, load_uint8_to_r, 1, 0, {&registers.B}, {NULL}}, //0x06
	{0x07, "RLCA", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x07
	{0x08, "LD (nn),SP", 3, NULL, 0, 0, {NULL}, {NULL}}, //0x08
	{0x09, "ADD HL,BC", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x09
	{0x0A, "LD A,(BC)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x0A
	{0x0B, "DEC BC", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x0B
	{0x0C, "INC C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x0C
	{0x0D, "DEC C", 1, dec_uint8_from_r, 1, 0, {&registers.C}, {NULL}}, //0x0D
	{0x0E, "LD C,n", 2, load_uint8_to_r, 1, 0, {&registers.C}, {NULL}}, //0x0E
	{0x0F, "RRCA", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x0F
	{0x10, "STOP", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x10
	{0x11, "LD DE,nn", 2, NULL, 0, 0, {NULL}, {NULL}}, //0x11
	{0x12, "LD (DE),A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x12
	{0x13, "INC DE", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x13
	{0x14, "INC D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x14
	{0x15, "DEC D", 1, dec_uint8_from_r, 1, 0, {&registers.D}, {NULL}}, //0x15
	{0x16, "LD D,n", 2, load_uint8_to_r, 1, 0, {&registers.D}, {NULL}}, //0x16
	{0x17, "RLA", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x17
	{0x18, "JR e", 2, NULL, 0, 0, {NULL}, {NULL}}, //0x18
	{0x19, "ADD HL,DE", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x19
	{0x1A, "LD A,(DE)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x1A
	{0x1B, "DEC DE", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x1B
	{0x1C, "INC E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x1C
	{0x1D, "DEC E", 1, dec_uint8_from_r, 1, 0, {&registers.E}, {}}, //0x1D
	{0x1E, "LD E,n", 2, load_uint8_to_r, 1, 0, {&registers.E}, {NULL}}, //0x1E
	{0x1F, "RRA", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x1F
	{0x20, "JR NZ,e", 2, NZ_relative_jump_to_e, 0, 0, {NULL}, {NULL}}, //0x20
	{0x21, "LD HL,nn", 3, load_uint16_to_r, 0, 1, {NULL}, {&registers.HL}}, //0x21
	{0x22, "LD (HL+),A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x22
	{0x23, "INC HL", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x23
	{0x24, "INC H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x24
	{0x25, "DEC H", 1, dec_uint8_from_r, 1, 0, {&registers.H}, {NULL}}, //0x25
	{0x26, "LD H,n", 2, load_uint8_to_r, 1, 0, {&registers.H}, {NULL}}, //0x26
	{0x27, "DAA", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x27
	{0x28, "JR Z,e", 2, Z_relative_jump_to_e, 0, 0, {NULL}, {NULL}}, //0x28
	{0x29, "ADD HL,HL", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x29
	{0x2A, "LD A(HL+)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x2A
	{0x2B, "DEC HL", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x2B
	{0x2C, "INC L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x2C
	{0x2D, "DEC L", 1, dec_uint8_from_r, 1, 0, {&registers.L}, {NULL}}, //0x2D
	{0x2E, "LD L,n", 2, load_uint8_to_r, 1, 0, {&registers.L}, {NULL}}, //0x2E
	{0x2F, "CPL", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x2F
	{0x30, "JR NC,e", 2, NC_relative_jump_to_e, 0, 0, {NULL}, {NULL}}, //0x30
	{0x31, "LD SP,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0x31
	{0x32, "LD (HL-),A", 1, load_from_A_dec_HL, 0, 1, {NULL}, {NULL}}, //0x32
	{0x33, "INC SP", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x33
	{0x34, "INC (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x34
	{0x35, "DEC (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x35
	{0x36, "LD (HL),n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0x36
	{0x37, "SCF", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x37
	{0x38, "JR C,e", 2, C_relative_jump_to_e, 0, 0, {NULL}, {NULL}}, //0x38
	{0x39, "ADD HL,SP", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x39
	{0x3A, "LD A,(HL-)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x3A
	{0x3B, "DEC SP", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x3B
	{0x3C, "INC A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x3C
	{0x3D, "DEC A", 1, dec_uint8_from_r, 1, 0, {&registers.A}, {NULL}}, //0x3D
	{0x3E, "LD A,n", 2, load_uint8_to_r, 1, 0, {&registers.A}, {NULL}}, //0x3E
	{0x3F, "CCF", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x3F
	{0x40, "LD B,B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x40
	{0x41, "LD B,C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x41
	{0x42, "LD B,D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x42
	{0x43, "LD B,E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x43
	{0x44, "LD B,H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x44
	{0x45, "LD B,L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x45
	{0x46, "LD B,(HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x46
	{0x47, "LD B,A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x47
	{0x48, "LD C,B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x48
	{0x49, "LD C,C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x49
	{0x4A, "LD C,D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x4A
	{0x4B, "LD C,E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x4B
	{0x4C, "LD C,H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x4C
	{0x4D, "LD C,L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x4D
	{0x4E, "LD C,(HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x4E
	{0x4F, "LD C,A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x4F
	{0x50, "LD D,B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x50
	{0x51, "LD D,C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x51
	{0x52, "LD D,D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x52
	{0x53, "LD D,E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x53
	{0x54, "LD D,H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x54
	{0x55, "LD D,L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x55
	{0x56, "LD D,(HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x56
	{0x57, "LD D,A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x57
	{0x58, "LD E,B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x58
	{0x59, "LD E,C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x59
	{0x5A, "LD E,D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x5A
	{0x5B, "LD E,E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x5B
	{0x5C, "LD E,H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x5C
	{0x5D, "LD E,L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x5D
	{0x5E, "LD E,(HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x5E
	{0x5F, "LD E,A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x5F
	{0x60, "LD H,B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x60
	{0x61, "LD H,C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x61
	{0x62, "LD H,D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x62
	{0x63, "LD H,E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x63
	{0x64, "LD H,H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x64
	{0x65, "LD H,L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x65
	{0x66, "LD H,(HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x66
	{0x67, "LD H,A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x67
	{0x68, "LD L,B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x68
	{0x69, "LD L,C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x69
	{0x6A, "LD L,D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x6A
	{0x6B, "LD L,E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x6B
	{0x6C, "LD L,H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x6C
	{0x6D, "LD L,L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x6D
	{0x6E, "LD L,(HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x6E
	{0x6F, "LD L,A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x6F
	{0x70, "LD (HL),B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x70
	{0x71, "LD (HL),C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x71
	{0x72, "LD (HL),D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x72
	{0x73, "LD (HL),E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x73
	{0x74, "LD (HL),H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x74
	{0x75, "LD (HL),L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x75
	{0x76, "HALT", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x76
	{0x77, "LD (HL),A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x77
	{0x78, "LD A,B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x78
	{0x79, "LD A,C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x79
	{0x7A, "LD A,D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x7A
	{0x7B, "LD A,E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x7B
	{0x7C, "LD A,H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x7C
	{0x7D, "LD A,L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x7D
	{0x7E, "LD A,(HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x7E
	{0x7F, "LD A,A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x7F
	{0x80, "ADD B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x80
	{0x81, "ADD C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x81
	{0x82, "ADD D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x82
	{0x83, "ADD E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x83
	{0x84, "ADD H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x84
	{0x85, "ADD L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x85
	{0x86, "ADD (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x86
	{0x87, "ADD A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x87
	{0x88, "ADC B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x88
	{0x89, "ADC C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x89
	{0x8A, "ADC D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x8A
	{0x8B, "ADC E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x8B
	{0x8C, "ADC H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x8C
	{0x8D, "ADC L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x8D
	{0x8E, "ADC (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x8E
	{0x8F, "ADC A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x8F
	{0x90, "SUB B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x90
	{0x91, "SUB C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x91
	{0x92, "SUB D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x92
	{0x93, "SUB E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x93
	{0x94, "SUB H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x94
	{0x95, "SUB L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x95
	{0x96, "SUB (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x96
	{0x97, "SUB A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x97
	{0x98, "SBC B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x98
	{0x99, "SBC C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x99
	{0x9A, "SBC D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x9A
	{0x9B, "SBC E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x9B
	{0x9C, "SBC H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x9C
	{0x9D, "SBC L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x9D
	{0x9E, "SBC (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x9E
	{0x9F, "SBC A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0x9F
	{0xA0, "AND B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xA0
	{0xA1, "AND C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xA1
	{0xA2, "AND D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xA2
	{0xA3, "AND E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xA3
	{0xA4, "AND H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xA4
	{0xA5, "AND L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xA5
	{0xA6, "AND (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xA6
	{0xA7, "AND A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xA7
	{0xA8, "XOR B", 1, exclusive_or_A_to_r, 1, 0, {&registers.B}, {NULL}}, //0xA8
	{0xA9, "XOR C", 1, exclusive_or_A_to_r, 1, 0, {&registers.C}, {NULL}}, //0xA9
	{0xAA, "XOR D", 1, exclusive_or_A_to_r, 1, 0, {&registers.D}, {NULL}}, //0xAA
	{0xAB, "XOR E", 1, exclusive_or_A_to_r, 1, 0, {&registers.E}, {NULL}}, //0xAB
	{0xAC, "XOR H", 1, exclusive_or_A_to_r, 1, 0, {&registers.H}, {NULL}}, //0xAC
	{0xAD, "XOR L", 1, exclusive_or_A_to_r, 1, 0, {&registers.L}, {NULL}}, //0xAD
	{0xAE, "XOR (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xAE
	{0xAF, "XOR A", 1, exclusive_or_A_to_r, 1, 0, {&registers.A}, {NULL}}, //0xAF
	{0xB0, "OR B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB0
	{0xB1, "OR C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB1
	{0xB2, "OR D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB2
	{0xB3, "OR E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB3
	{0xB4, "OR H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB4
	{0xB5, "OR L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB5
	{0xB6, "OR (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB6
	{0xB7, "OR A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB7
	{0xB8, "CP B", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB8
	{0xB9, "CP C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xB9
	{0xBA, "CP D", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xBA
	{0xBB, "CP E", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xBB
	{0xBC, "CP H", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xBC
	{0xBD, "CP L", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xBD
	{0xBE, "CP (HL)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xBE
	{0xBF, "CP A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xBF
	{0xC0, "RET NZ", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xC0
	{0xC1, "POP BC", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xC1
	{0xC2, "JP NZ,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xC2
	{0xC3, "JP nn", 3, unconditional_jump, 0, 0, {NULL}, {NULL}}, //0xC3
	{0xC4, "CALL NZ,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xC4
	{0xC5, "PUSH BC", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xC5
	{0xC6, "ADD n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xC6
	{0xC7, "RST 0x00", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xC7
	{0xC8, "RET Z", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xC8
	{0xC9, "RET", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xC9
	{0xCA, "JP Z,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xCA
	{0xCB, "CB op", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xCB
	{0xCC, "CALL Z,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xCC
	{0xCD, "CALL nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xCD
	{0xCE, "ADC n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xCE
	{0xCF, "RST 0x08", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xCF
	{0xD0, "RET NC", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xD0
	{0xD1, "POP DE", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xD1
	{0xD2, "JP NC,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xD2
	{0xD3, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xD3
	{0xD4, "CALL NC,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xD4
	{0xD5, "PUSH DE", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xD5
	{0xD6, "SUB n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xD6
	{0xD7, "RST 0x10", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xD7
	{0xD8, "RET C", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xD8
	{0xD9, "RETI", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xD9
	{0xDA, "JP C,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xDA
	{0xDB, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xDB
	{0xDC, "CALL C,nn", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xDC
	{0xDD, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xDD
	{0xDE, "SBC n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xDE
	{0xDF, "RST 0x18", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xDF
	{0xE0, "LDH (n),A", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xE0
	{0xE1, "POP HL", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xE1
	{0xE2, "LDH (C),A", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xE2
	{0xE3, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xE3
	{0xE4, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xE4
	{0xE5, "PUSH HL", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xE5
	{0xE6, "AND n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xE6
	{0xE7, "RST 0x20", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xE7
	{0xE8, "ADD SP,e", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xE8
	{0xE9, "JP HL", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xE9
	{0xEA, "LD (nn),A", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xEA
	{0xEB, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xEB
	{0xEC, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xEC
	{0xED, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xED
	{0xEE, "XOR  n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xEE
	{0xEF, "RST 0x28", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xEF
	{0xF0, "LDH A,(n)", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xF0
	{0xF1, "POP AF", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xF1
	{0xF2, "LDH A,(C)", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xF2
	{0xF3, "DI", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xF3
	{0xF4, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xF4
	{0xF5, "PUSH AF", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xF5
	{0xF6, "OR n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xF6
	{0xF7, "RST 0x30", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xF7
	{0xF8, "LD HL,SP+e", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xF8
	{0xF9, "LD SP,HL", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xF9
	{0xFA, "LD A,(nn)", 3, NULL, 0, 0, {NULL}, {NULL}}, //0xFA
	{0xFB, "EI", 1, NULL, 0, 0, {NULL}, {NULL}}, //0xFB
	{0xFC, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xFC
	{0xFD, "UNDEF", 0, NULL, 0, 0, {NULL}, {NULL}}, //0xFD
	{0xFE, "CP n", 2, NULL, 0, 0, {NULL}, {NULL}}, //0xFE
	{0xFF, "RST 0x38", 1, NULL, 0, 0, {NULL}, {NULL}} //0xFF
};
