#include <stddef.h>
#include "instr.h"
#include "alu.h"

const sm83_instruction instruction_set[256] = {
	{"NOP", 1, no_operation}, //0x00
	{"LD BC,nn", 3, NULL}, //0x01
	{"LD (BC),A", 1, NULL}, //0x02
	{"INC BC", 1, NULL}, //0x03
	{"INC B", 1, NULL}, //0x04
	{"DEC B", 1, NULL}, //0x05
	{"LD B,n", 2, NULL}, //0x06
	{"RLCA", 1, NULL}, //0x07
	{"LD (nn),SP", 3, NULL}, //0x08
	{"ADD HL,BC", 1, NULL}, //0x09
	{"LD A,(BC)", 1, NULL}, //0x0A
	{"DEC BC", 1, NULL}, //0x0B
	{"INC C", 1, NULL}, //0x0C
	{"DEC C", 1, NULL}, //0x0D
	{"LD C,n", 2, NULL}, //0x0E
	{"RRCA", 1, NULL}, //0x0F
	{"STOP", 1, NULL}, //0x10
	{"LD DE,nn", 2, NULL}, //0x11
	{"LD (DE),A", 1, NULL}, //0x12
	{"INC DE", 1, NULL}, //0x13
	{"INC D", 1, NULL}, //0x14
	{"DEC D", 1, NULL}, //0x15
	{"LD D,n", 2, NULL}, //0x16
	{"RLA", 1, NULL}, //0x17
	{"JR e", 2, NULL}, //0x18
	{"ADD HL,DE", 1, NULL}, //0x19
	{"LD A,(DE)", 1, NULL}, //0x1A
	{"DEC DE", 1, NULL}, //0x1B
	{"INC E", 1, NULL}, //0x1C
	{"DEC E", 1, NULL}, //0x1D
	{"LD E,n", 2, NULL}, //0x1E
	{"RRA", 1, NULL}, //0x1F
	{"JR NZ,e", 2, NULL}, //0x20
	{"LD HL,nn", 3, NULL}, //0x21
	{"LD (HL+),A", 1, NULL}, //0x22
	{"INC HL", 1, NULL}, //0x23
	{"INC H", 1, NULL}, //0x24
	{"DEC H", 1, NULL}, //0x25
	{"LD H,n", 2, NULL}, //0x26
	{"DAA", 1, NULL}, //0x27
	{"JR Z,e", 2, NULL}, //0x28
	{"ADD HL,HL", 1, NULL}, //0x29
	{"LD A(HL+)", 1, NULL}, //0x2A
	{"DEC HL", 1, NULL}, //0x2B
	{"INC L", 1, NULL}, //0x2C
	{"DEC L", 1, NULL}, //0x2D
	{"LD L,n", 2, NULL}, //0x2E
	{"CPL", 1, NULL}, //0x2F
	{"JR NC,e", 2, NULL}, //0x30
	{"LD SP,nn", 3, NULL}, //0x31
	{"LD (HL-),A", 1, NULL}, //0x32
	{"INC SP", 1, NULL}, //0x33
	{"INC (HL)", 1, NULL}, //0x34
	{"DEC (HL)", 1, NULL}, //0x35
	{"LD (HL),n", 2, NULL}, //0x36
	{"SCF", 1, NULL}, //0x37
	{"JR C,e", 2, NULL}, //0x38
	{"ADD HL,SP", 1, NULL}, //0x39
	{"LD A,(HL-)", 1, NULL}, //0x3A
	{"DEC SP", 1, NULL}, //0x3B
	{"INC A", 1, NULL}, //0x3C
	{"DEC A", 1, NULL}, //0x3D
	{"LD A,n", 2, NULL}, //0x3E
	{"CCF", 1, NULL}, //0x3F
	{"LD B,B", 1, NULL}, //0x40
	{"LD B,C", 1, NULL}, //0x41
	{"LD B,D", 1, NULL}, //0x42
	{"LD B,E", 1, NULL}, //0x43
	{"LD B,H", 1, NULL}, //0x44
	{"LD B,L", 1, NULL}, //0x45
	{"LD B,(HL)", 1, NULL}, //0x46
	{"LD B,A", 1, NULL}, //0x47
	{"LD C,B", 1, NULL}, //0x48
	{"LD C,C", 1, NULL}, //0x49
	{"LD C,D", 1, NULL}, //0x4A
	{"LD C,E", 1, NULL}, //0x4B
	{"LD C,H", 1, NULL}, //0x4C
	{"LD C,L", 1, NULL}, //0x4D
	{"LD C,(HL)", 1, NULL}, //0x4E
	{"LD C,A", 1, NULL}, //0x4F
	{"LD D,B", 1, NULL}, //0x50
	{"LD D,C", 1, NULL}, //0x51
	{"LD D,D", 1, NULL}, //0x52
	{"LD D,E", 1, NULL}, //0x53
	{"LD D,H", 1, NULL}, //0x54
	{"LD D,L", 1, NULL}, //0x55
	{"LD D,(HL)", 1, NULL}, //0x56
	{"LD D,A", 1, NULL}, //0x57
	{"LD E,B", 1, NULL}, //0x58
	{"LD E,C", 1, NULL}, //0x59
	{"LD E,D", 1, NULL}, //0x5A
	{"LD E,E", 1, NULL}, //0x5B
	{"LD E,H", 1, NULL}, //0x5C
	{"LD E,L", 1, NULL}, //0x5D
	{"LD E,(HL)", 1, NULL}, //0x5E
	{"LD E,A", 1, NULL}, //0x5F
	{"LD H,B", 1, NULL}, //0x60
	{"LD H,C", 1, NULL}, //0x61
	{"LD H,D", 1, NULL}, //0x62
	{"LD H,E", 1, NULL}, //0x63
	{"LD H,H", 1, NULL}, //0x64
	{"LD H,L", 1, NULL}, //0x65
	{"LD H,(HL)", 1, NULL}, //0x66
	{"LD H,A", 1, NULL}, //0x67
	{"LD L,B", 1, NULL}, //0x68
	{"LD L,C", 1, NULL}, //0x69
	{"LD L,D", 1, NULL}, //0x6A
	{"LD L,E", 1, NULL}, //0x6B
	{"LD L,H", 1, NULL}, //0x6C
	{"LD L,L", 1, NULL}, //0x6D
	{"LD L,(HL)", 1, NULL}, //0x6E
	{"LD L,A", 1, NULL}, //0x6F
	{"LD (HL),B", 1, NULL}, //0x70
	{"LD (HL),C", 1, NULL}, //0x71
	{"LD (HL),D", 1, NULL}, //0x72
	{"LD (HL),E", 1, NULL}, //0x73
	{"LD (HL),H", 1, NULL}, //0x74
	{"LD (HL),L", 1, NULL}, //0x75
	{"HALT", 1, NULL}, //0x76
	{"LD (HL),A", 1, NULL}, //0x77
	{"LD A,B", 1, NULL}, //0x78
	{"LD A,C", 1, NULL}, //0x79
	{"LD A,D", 1, NULL}, //0x7A
	{"LD A,E", 1, NULL}, //0x7B
	{"LD A,H", 1, NULL}, //0x7C
	{"LD A,L", 1, NULL}, //0x7D
	{"LD A,(HL)", 1, NULL}, //0x7E
	{"LD A,A", 1, NULL}, //0x7F
	{"ADD B", 1, NULL}, //0x80
	{"ADD C", 1, NULL}, //0x81
	{"ADD D", 1, NULL}, //0x82
	{"ADD E", 1, NULL}, //0x83
	{"ADD H", 1, NULL}, //0x84
	{"ADD L", 1, NULL}, //0x85
	{"ADD (HL)", 1, NULL}, //0x86
	{"ADD A", 1, NULL}, //0x87
	{"ADC B", 1, NULL}, //0x88
	{"ADC C", 1, NULL}, //0x89
	{"ADC D", 1, NULL}, //0x8A
	{"ADC E", 1, NULL}, //0x8B
	{"ADC H", 1, NULL}, //0x8C
	{"ADC L", 1, NULL}, //0x8D
	{"ADC (HL)", 1, NULL}, //0x8E
	{"ADC A", 1, NULL}, //0x8F
	{"SUB B", 1, NULL}, //0x90
	{"SUB C", 1, NULL}, //0x91
	{"SUB D", 1, NULL}, //0x92
	{"SUB E", 1, NULL}, //0x93
	{"SUB H", 1, NULL}, //0x94
	{"SUB L", 1, NULL}, //0x95
	{"SUB (HL)", 1, NULL}, //0x96
	{"SUB A", 1, NULL}, //0x97
	{"SBC B", 1, NULL}, //0x98
	{"SBC C", 1, NULL}, //0x99
	{"SBC D", 1, NULL}, //0x9A
	{"SBC E", 1, NULL}, //0x9B
	{"SBC H", 1, NULL}, //0x9C
	{"SBC L", 1, NULL}, //0x9D
	{"SBC (HL)", 1, NULL}, //0x9E
	{"SBC A", 1, NULL}, //0x9F
	{"AND B", 1, NULL}, //0xA0
	{"AND C", 1, NULL}, //0xA1
	{"AND D", 1, NULL}, //0xA2
	{"AND E", 1, NULL}, //0xA3
	{"AND H", 1, NULL}, //0xA4
	{"AND L", 1, NULL}, //0xA5
	{"AND (HL)", 1, NULL}, //0xA6
	{"AND A", 1, NULL}, //0xA7
	{"XOR B", 1, NULL}, //0xA8
	{"XOR C", 1, NULL}, //0xA9
	{"XOR D", 1, NULL}, //0xAA
	{"XOR E", 1, NULL}, //0xAB
	{"XOR H", 1, NULL}, //0xAC
	{"XOR L", 1, NULL}, //0xAD
	{"XOR (HL)", 1, NULL}, //0xAE
	{"XOR A", 1, NULL}, //0xAF
	{"OR B", 1, NULL}, //0xB0
	{"OR C", 1, NULL}, //0xB1
	{"OR D", 1, NULL}, //0xB2
	{"OR E", 1, NULL}, //0xB3
	{"OR H", 1, NULL}, //0xB4
	{"OR L", 1, NULL}, //0xB5
	{"OR (HL)", 1, NULL}, //0xB6
	{"OR A", 1, NULL}, //0xB7
	{"CP B", 1, NULL}, //0xB8
	{"CP C", 1, NULL}, //0xB9
	{"CP D", 1, NULL}, //0xBA
	{"CP E", 1, NULL}, //0xBB
	{"CP H", 1, NULL}, //0xBC
	{"CP L", 1, NULL}, //0xBD
	{"CP (HL)", 1, NULL}, //0xBE
	{"CP A", 1, NULL}, //0xBF
	{"RET NZ", 1, NULL}, //0xC0
	{"POP BC", 1, NULL}, //0xC1
	{"JP NZ,nn", 3, NULL}, //0xC2
	{"JP nn", 3, unconditional_jump}, //0xC3
	{"CALL NZ,nn", 3, NULL}, //0xC4
	{"PUSH BC", 1, NULL}, //0xC5
	{"ADD n", 2, NULL}, //0xC6
	{"RST 0x00", 1, NULL}, //0xC7
	{"RET Z", 1, NULL}, //0xC8
	{"RET", 1, NULL}, //0xC9
	{"JP Z,nn", 3, NULL}, //0xCA
	{"CB op", 1, NULL}, //0xCB
	{"CALL Z,nn", 3, NULL}, //0xCC
	{"CALL nn", 3, NULL}, //0xCD
	{"ADC n", 2, NULL}, //0xCE
	{"RST 0x08", 1, NULL}, //0xCF
	{"RET NC", 1, NULL}, //0xD0
	{"POP DE", 1, NULL}, //0xD1
	{"JP NC,nn", 3, NULL}, //0xD2
	{"UNDEF", 0, NULL}, //0xD3
	{"CALL NC,nn", 3, NULL}, //0xD4
	{"PUSH DE", 1, NULL}, //0xD5
	{"SUB n", 2, NULL}, //0xD6
	{"RST 0x10", 1, NULL}, //0xD7
	{"RET C", 1, NULL}, //0xD8
	{"RETI", 1, NULL}, //0xD9
	{"JP C,nn", 3, NULL}, //0xDA
	{"UNDEF", 0, NULL}, //0xDB
	{"CALL C,nn", 3, NULL}, //0xDC
	{"UNDEF", 0, NULL}, //0xDD
	{"SBC n", 2, NULL}, //0xDE
	{"RST 0x18", 1, NULL}, //0xDF
	{"LDH (n),A", 2, NULL}, //0xE0
	{"POP HL", 1, NULL}, //0xE1
	{"LDH (C),A", 1, NULL}, //0xE2
	{"UNDEF", 0, NULL}, //0xE3
	{"UNDEF", 0, NULL}, //0xE4
	{"PUSH HL", 1, NULL}, //0xE5
	{"AND n", 2, NULL}, //0xE6
	{"RST 0x20", 1, NULL}, //0xE7
	{"ADD SP,e", 2, NULL}, //0xE8
	{"JP HL", 1, NULL}, //0xE9
	{"LD (nn),A", 3, NULL}, //0xEA
	{"UNDEF", 0, NULL}, //0xEB
	{"UNDEF", 0, NULL}, //0xEC
	{"UNDEF", 0, NULL}, //0xED
	{"XOR  n", 2, NULL}, //0xEE
	{"RST 0x28", 1, NULL}, //0xEF
	{"LDH A,(n)", 2, NULL}, //0xF0
	{"POP AF", 1, NULL}, //0xF1
	{"LDH A,(C)", 1, NULL}, //0xF2
	{"DI", 1, NULL}, //0xF3
	{"UNDEF", 0, NULL}, //0xF4
	{"PUSH AF", 1, NULL}, //0xF5
	{"OR n", 2, NULL}, //0xF6
	{"RST 0x30", 1, NULL}, //0xF7
	{"LD HL,SP+e", 2, NULL}, //0xF8
	{"LD SP,HL", 1, NULL}, //0xF9
	{"LD A,(nn)", 3, NULL}, //0xFA
	{"EI", 1, NULL}, //0xFB
	{"UNDEF", 0, NULL}, //0xFC
	{"UNDEF", 0, NULL}, //0xFD
	{"CP n", 2, NULL}, //0xFE
	{"RST 0x38", 1, NULL} //0xFF
};
