/**
 * This file contains 4-operator MIDI instrument defenitions for use with the OPL2 Audio Board library. These were
 * converted from the General MIDI timbres by The Fat Man(TM). This file contains the melodic instrments only.
 *
 * Instrument definition is based on Adlib instrument bank format.
 *  0 - Transpose
 *		Tells the number of semi-tones a note that is played using this instrument should be pitched up or down. For
 *		drum instruments that are played in melodic mode this sets the absolute note to be played for the drum sound.
 *
 *  1 - Channel c, operator 1, register 0x20
 *		Tremolo(1) | Vibrato(1) | Sustain(1) | KSR(1) | Frequency multiplier (4)
 *
 *  2 - Channel c, operator 1, register 0x40
 *		Key scale level(2) | Output level(6)
 *
 *  3 - Channel c, operator 1, register 0x60
 *		Attack(4) | Decay(4)
 *
 *  4 - Channel c, operator 1, register 0x80
 *		Sustain(4) | Release(4)
 *
 *  5 - Channel c, register 0xC0
 *		Undefined(4) | Modulation feedback factor(3) | Synth type(1)
 *
 *  6 - Channel c, operator 2, register 0x20
 *  7 - Channel c, operator 2, register 0x40
 *  8 - Channel c, operator 2, register 0x60
 *  9 - Channel c, operator 2, register 0x80
 *
 * 10 - Channel c, operators 1 + 2, register 0xE0
 *		OP1 WaveForm(3) | OP2 Waveform(3)
 *
 * 11 - Channel d, operator 3, register 0x20
 * 12 - Channel d, operator 3, register 0x40
 * 13 - Channel d, operator 3, register 0x60
 * 14 - Channel d, operator 3, register 0x80
 * 15 - Channel d, register 0xC0
 * 16 - Channel d, operator 4, register 0x20
 * 17 - Channel d, operator 4, register 0x40
 * 18 - Channel d, operator 4, register 0x60
 * 19 - Channel d, operator 4, register 0x80
 * 20 - Channel d, operators 3 + 4, register 0xE0
 */

#ifndef _MIDI_INST4OP_H_
	#define _MIDI_INST4OP_H_

	const unsigned char INSTRUMENT_PIANO1[21]   = { 0x00, 0x31, 0x8F, 0xF1, 0xB2, 0x08, 0x11, 0x83, 0xF1, 0xAF, 0x00, 0x31, 0x19, 0xF1, 0xB2, 0x01, 0x31, 0x01, 0xC1, 0xD5, 0x00 };
	const unsigned char INSTRUMENT_PIANO2[21]   = { 0x00, 0x11, 0x4C, 0xF1, 0xD2, 0x0A, 0x11, 0x83, 0xF2, 0xE6, 0x00, 0x11, 0x15, 0xC1, 0xD5, 0x01, 0x31, 0x00, 0xC2, 0xE6, 0x00 };
	const unsigned char INSTRUMENT_PIANO3[21]   = { 0x00, 0x15, 0x5F, 0xF3, 0xD4, 0x0E, 0x15, 0x61, 0xB1, 0xE4, 0x00, 0x11, 0x5C, 0xB1, 0xE4, 0x00, 0x11, 0x00, 0xB1, 0xB5, 0x00 };
	const unsigned char INSTRUMENT_HONKTONK[21] = { 0x00, 0x11, 0x89, 0xF1, 0xD4, 0x0D, 0x02, 0x5F, 0xC3, 0xE4, 0x00, 0x00, 0x9B, 0xC1, 0x35, 0x00, 0x11, 0x00, 0xC1, 0xD5, 0x00 };
	const unsigned char INSTRUMENT_EP1[21]      = { 0x00, 0x1C, 0x6F, 0xF2, 0xE7, 0x0C, 0x01, 0x80, 0xF2, 0xB8, 0x00, 0x11, 0x9C, 0xB1, 0xE5, 0x01, 0x11, 0x80, 0xF2, 0xB8, 0x00 };
	const unsigned char INSTRUMENT_EP2[21]      = { 0x00, 0x1C, 0x3A, 0xC2, 0xE7, 0x00, 0x01, 0x80, 0xF3, 0xB8, 0x00, 0x11, 0x1B, 0xB1, 0xF5, 0x01, 0x11, 0x80, 0xF2, 0xD8, 0x00 };
	const unsigned char INSTRUMENT_HARPSIC[21]  = { 0x00, 0x31, 0x90, 0xF0, 0x31, 0x08, 0x34, 0x9F, 0xF2, 0x37, 0x00, 0x24, 0x1C, 0xF3, 0x51, 0x00, 0x11, 0x00, 0xF2, 0x97, 0x44 };
	const unsigned char INSTRUMENT_CLAVIC[21]   = { 0x00, 0x10, 0x60, 0xF2, 0x50, 0x04, 0x31, 0x5D, 0xE1, 0xF0, 0x00, 0x30, 0xA2, 0xB2, 0x40, 0x00, 0x11, 0x80, 0xF1, 0xE9, 0x50 };
	const unsigned char INSTRUMENT_CELESTA[21]  = { 0x00, 0x02, 0x25, 0xCE, 0xE6, 0x00, 0x01, 0x00, 0xF4, 0xE6, 0x00, 0x07, 0xA1, 0xF5, 0xE6, 0x01, 0x41, 0x00, 0xF3, 0xE5, 0x00 };
	const unsigned char INSTRUMENT_GLOCK[21]    = { 0x00, 0x17, 0x54, 0xF2, 0xE3, 0x0A, 0x11, 0x06, 0xC2, 0xE2, 0x00, 0x19, 0x2B, 0xF2, 0xC3, 0x01, 0x91, 0x07, 0xF2, 0xD2, 0x00 };
	const unsigned char INSTRUMENT_MUSICBOX[21] = { 0x00, 0x17, 0x21, 0x56, 0x04, 0x02, 0x01, 0x00, 0xF6, 0x04, 0x00, 0x1A, 0x27, 0xA6, 0x04, 0x01, 0x00, 0x0A, 0xF6, 0x04, 0x00 };
	const unsigned char INSTRUMENT_VIBES[21]    = { 0x00, 0x25, 0x9A, 0x08, 0x79, 0x0A, 0x85, 0x5B, 0xE3, 0xE6, 0x00, 0x15, 0x62, 0xF3, 0xE6, 0x01, 0x81, 0x00, 0xF2, 0xE6, 0x00 };
	const unsigned char INSTRUMENT_MARIMBA[21]  = { 0x00, 0x1C, 0xA3, 0xF7, 0x55, 0x06, 0x20, 0x0D, 0x85, 0xD8, 0x00, 0x18, 0x23, 0xF7, 0x55, 0x01, 0x21, 0x00, 0xE5, 0xD8, 0x00 };
	const unsigned char INSTRUMENT_XYLO[21]     = { 0x00, 0x0A, 0x53, 0xF9, 0xD6, 0x0A, 0x84, 0x80, 0xF7, 0xD6, 0x00, 0x15, 0x91, 0xF6, 0xA6, 0x01, 0x01, 0x00, 0xF6, 0xE6, 0x00 };
	const unsigned char INSTRUMENT_TUBEBELL[21] = { 0x00, 0x41, 0x8A, 0xD4, 0xB3, 0x04, 0x80, 0x13, 0xC2, 0xB4, 0x00, 0x45, 0x59, 0xD3, 0x82, 0x01, 0x81, 0x80, 0xA3, 0xE3, 0x00 };
	const unsigned char INSTRUMENT_SANTUR[21]   = { 0x00, 0x01, 0x84, 0xE7, 0xF7, 0x0D, 0x03, 0x49, 0x74, 0x55, 0x10, 0x01, 0x80, 0xB3, 0x05, 0x01, 0x01, 0x80, 0x76, 0xF7, 0x00 };
	const unsigned char INSTRUMENT_ORGAN1[21]   = { 0x00, 0xA0, 0x85, 0xA2, 0x2A, 0x07, 0x22, 0x9E, 0xA5, 0x2A, 0x00, 0xA2, 0x83, 0xA5, 0x2A, 0x01, 0x28, 0x95, 0xA1, 0x2A, 0x00 };
	const unsigned char INSTRUMENT_ORGAN2[21]   = { 0x00, 0xA0, 0x85, 0x91, 0x2A, 0x07, 0x21, 0x0B, 0xC8, 0x3A, 0x00, 0x20, 0x81, 0xC6, 0x38, 0x01, 0x21, 0x80, 0xF6, 0x57, 0x00 };
	const unsigned char INSTRUMENT_ORGAN3[21]   = { 0x00, 0xE3, 0x56, 0xA6, 0x2A, 0x08, 0x61, 0x83, 0xAF, 0x0A, 0x01, 0xE1, 0x91, 0xAF, 0x0A, 0x01, 0x62, 0x83, 0xAF, 0x0A, 0x00 };
	const unsigned char INSTRUMENT_PIPEORG[21]  = { 0x00, 0x25, 0x5F, 0xB0, 0x02, 0x0C, 0x30, 0x40, 0x70, 0x05, 0x00, 0x31, 0x46, 0xC0, 0x02, 0x01, 0x31, 0x80, 0x60, 0x05, 0x00 };
	const unsigned char INSTRUMENT_REEDORG[21]  = { 0x00, 0x21, 0x93, 0xC8, 0x15, 0x0C, 0x31, 0x00, 0x6F, 0x05, 0x00, 0x31, 0x16, 0xCF, 0x05, 0x01, 0x32, 0x87, 0x7F, 0x05, 0x00 };
	const unsigned char INSTRUMENT_ACORDIAN[21] = { 0x00, 0x23, 0xAC, 0x72, 0x1A, 0x00, 0x21, 0x83, 0x72, 0x2A, 0x07, 0x23, 0x22, 0x62, 0x1A, 0x01, 0xA1, 0x00, 0x62, 0x2A, 0x04 };
	const unsigned char INSTRUMENT_HARMONIC[21] = { 0x00, 0x25, 0xA1, 0xFF, 0x06, 0x0A, 0x23, 0x2F, 0xFF, 0x05, 0x00, 0xA1, 0x1F, 0xFF, 0x05, 0x00, 0x22, 0x80, 0x6F, 0x09, 0x04 };
	const unsigned char INSTRUMENT_BANDNEON[21] = { 0x00, 0x23, 0x19, 0x62, 0x1A, 0x0C, 0x21, 0x80, 0x72, 0x2A, 0x01, 0x23, 0x1E, 0x62, 0x1A, 0x01, 0x22, 0x83, 0x72, 0x2A, 0x04 };
	const unsigned char INSTRUMENT_NYLONGT[21]  = { 0x00, 0x02, 0x9C, 0xF3, 0x74, 0x0A, 0x41, 0x80, 0xF3, 0xB8, 0x00, 0x02, 0xA5, 0xD3, 0x74, 0x01, 0x82, 0x40, 0xD3, 0xB8, 0x02 };
	const unsigned char INSTRUMENT_STEELGT[21]  = { 0x00, 0x34, 0x5B, 0xF2, 0xF6, 0x0C, 0x31, 0x9E, 0xF2, 0xF7, 0x02, 0x23, 0xAB, 0xF2, 0xF7, 0x00, 0x11, 0x00, 0xF1, 0xE7, 0x00 };
	const unsigned char INSTRUMENT_JAZZGT[21]   = { 0x00, 0x22, 0x53, 0xF3, 0xFA, 0x0A, 0x23, 0x66, 0xF2, 0xFA, 0x00, 0x21, 0xA7, 0xC2, 0xFA, 0x00, 0x21, 0x00, 0xC2, 0xF7, 0x00 };
	const unsigned char INSTRUMENT_CLEANGT[21]  = { 0x00, 0x02, 0x4C, 0xFA, 0x22, 0x08, 0x01, 0x97, 0xF3, 0xF3, 0x00, 0x04, 0x9D, 0xC2, 0xF3, 0x00, 0x11, 0x00, 0xC1, 0xF7, 0x01 };
	const unsigned char INSTRUMENT_MUTEGT[21]   = { 0x00, 0x11, 0x87, 0xC7, 0xAF, 0x08, 0x01, 0x00, 0xF5, 0xF8, 0x00, 0x01, 0x18, 0xC3, 0x98, 0x01, 0x02, 0x00, 0xC3, 0xF8, 0x00 };
	const unsigned char INSTRUMENT_OVERDGT[21]  = { 0x00, 0x13, 0x0D, 0xB9, 0xF2, 0x0A, 0x02, 0x1A, 0x91, 0x11, 0x04, 0x21, 0x99, 0x92, 0x4A, 0x00, 0x22, 0x00, 0x91, 0x2A, 0x01 };
	const unsigned char INSTRUMENT_DISTGT[21]   = { 0x00, 0x23, 0x96, 0xF8, 0x42, 0x00, 0x22, 0x1A, 0x91, 0xFA, 0x22, 0x21, 0x99, 0x92, 0xBA, 0x00, 0x22, 0x00, 0x91, 0x4A, 0x00 };
	const unsigned char INSTRUMENT_GTHARMS[21]  = { 0x00, 0x09, 0xA1, 0x20, 0x4F, 0x08, 0x04, 0x80, 0xD1, 0xF8, 0x00, 0x02, 0x87, 0xF8, 0xF8, 0x01, 0x02, 0x00, 0xF6, 0xF8, 0x02 };
	const unsigned char INSTRUMENT_ACOUBASS[21] = { 0x00, 0x01, 0x4D, 0xA7, 0x15, 0x02, 0x01, 0x00, 0xA3, 0xC8, 0x00, 0x01, 0x93, 0x71, 0x31, 0x01, 0x01, 0x00, 0x73, 0xC8, 0x00 };
	const unsigned char INSTRUMENT_FINGBASS[21] = { 0x00, 0x11, 0xA8, 0xF1, 0xE5, 0x04, 0x12, 0x57, 0xF3, 0xE5, 0x00, 0x11, 0x97, 0xE1, 0xE5, 0x00, 0x11, 0x00, 0xE1, 0xE6, 0x00 };
	const unsigned char INSTRUMENT_PICKBASS[21] = { 0x00, 0x01, 0xB3, 0xF0, 0xC7, 0x06, 0x01, 0x16, 0xF1, 0x27, 0x00, 0x01, 0x16, 0xF1, 0x27, 0x00, 0x01, 0x00, 0xF1, 0x28, 0x00 };
	const unsigned char INSTRUMENT_FRETLESS[21] = { 0x00, 0x31, 0x5B, 0x51, 0x28, 0x0C, 0x32, 0x00, 0x71, 0x48, 0x00, 0x31, 0x19, 0x71, 0x48, 0x01, 0x31, 0x00, 0x71, 0x48, 0x00 };
	const unsigned char INSTRUMENT_SLAPBAS1[21] = { 0x00, 0x01, 0x8B, 0xA1, 0x9A, 0x08, 0x21, 0x40, 0xF2, 0xDF, 0x00, 0x04, 0x0B, 0xF9, 0xDA, 0x01, 0x01, 0x80, 0xF7, 0xDF, 0x00 };
	const unsigned char INSTRUMENT_SLAPBAS2[21] = { 0x00, 0x01, 0x89, 0xA1, 0x9A, 0x06, 0x21, 0x40, 0xF2, 0xDF, 0x00, 0x04, 0x0B, 0xF9, 0xDA, 0x01, 0x01, 0x80, 0xF7, 0xDF, 0x00 };
	const unsigned char INSTRUMENT_SYNBASS1[21] = { 0x00, 0x21, 0x1C, 0xF6, 0xC8, 0x0A, 0x01, 0x1F, 0xF1, 0xC8, 0x00, 0x01, 0xD8, 0xF1, 0xC8, 0x00, 0x01, 0x00, 0xF2, 0xC8, 0x00 };
	const unsigned char INSTRUMENT_SYNBASS2[21] = { 0x00, 0x21, 0x1C, 0xF6, 0xC8, 0x0A, 0x01, 0x1F, 0xF1, 0xC8, 0x01, 0x01, 0x12, 0x54, 0x42, 0x00, 0x01, 0x00, 0xF2, 0xC8, 0x00 };
	const unsigned char INSTRUMENT_VIOLIN[21]   = { 0x00, 0x31, 0x15, 0xDD, 0x13, 0x08, 0x21, 0x00, 0x56, 0x26, 0x01, 0x12, 0x95, 0x8D, 0x03, 0x01, 0x03, 0x8B, 0x65, 0x86, 0x01 };
	const unsigned char INSTRUMENT_VIOLA[21]    = { 0x00, 0x31, 0x17, 0xDD, 0x13, 0x08, 0x21, 0x00, 0x56, 0x26, 0x01, 0x12, 0x95, 0x8D, 0x03, 0x01, 0x03, 0x8B, 0x65, 0x86, 0x01 };
	const unsigned char INSTRUMENT_CELLO[21]    = { 0x00, 0x31, 0x95, 0xDD, 0x13, 0x08, 0x21, 0x00, 0x56, 0x26, 0x05, 0x13, 0x95, 0x8D, 0x03, 0x01, 0x05, 0x8C, 0x66, 0x86, 0x01 };
	const unsigned char INSTRUMENT_CONTRAB[21]  = { 0x00, 0x70, 0x92, 0xCC, 0x43, 0x0E, 0xA0, 0x03, 0x74, 0x17, 0x22, 0x21, 0x95, 0xBF, 0x07, 0x01, 0x21, 0x00, 0x6F, 0x07, 0x10 };
	const unsigned char INSTRUMENT_TREMSTR[21]  = { 0x00, 0x61, 0x97, 0xC2, 0x15, 0x06, 0xA1, 0x00, 0x6F, 0x05, 0x05, 0x63, 0x13, 0xB5, 0x8F, 0x01, 0xA5, 0x94, 0xB5, 0x8F, 0x00 };
	const unsigned char INSTRUMENT_PIZZ[21]     = { 0x00, 0x23, 0xA7, 0x85, 0x84, 0x0E, 0x12, 0xA4, 0x82, 0x74, 0x00, 0x02, 0x27, 0x82, 0x74, 0x00, 0x11, 0x00, 0x85, 0x35, 0x00 };
	const unsigned char INSTRUMENT_HARP[21]     = { 0x00, 0x23, 0xA7, 0x85, 0x84, 0x0E, 0x12, 0xA4, 0x82, 0x74, 0x00, 0x02, 0x27, 0x82, 0x74, 0x00, 0x11, 0x00, 0x84, 0x33, 0x00 };
	const unsigned char INSTRUMENT_TIMPANI[21]  = { 0x00, 0x10, 0x41, 0xF5, 0x05, 0x02, 0x11, 0x00, 0xF2, 0xC3, 0x01, 0x11, 0x01, 0xF5, 0x05, 0x01, 0x12, 0x1E, 0xF2, 0xC3, 0x00 };
	const unsigned char INSTRUMENT_STRINGS[21]  = { 0x00, 0x30, 0x98, 0x61, 0x03, 0x0E, 0xA0, 0x03, 0x64, 0x17, 0x22, 0x61, 0x92, 0x65, 0x17, 0x01, 0x21, 0x00, 0x65, 0x17, 0x01 };
	const unsigned char INSTRUMENT_SLOWSTR[21]  = { 0x00, 0x30, 0x98, 0x41, 0x23, 0x0E, 0x60, 0x01, 0x44, 0x17, 0x22, 0xA1, 0x98, 0x7F, 0x03, 0x01, 0x21, 0x00, 0x3F, 0x07, 0x11 };
	const unsigned char INSTRUMENT_SYNSTR1[21]  = { 0x00, 0x21, 0x1A, 0xC1, 0x12, 0x0C, 0x61, 0x00, 0x4F, 0x05, 0x00, 0xA1, 0x93, 0xC1, 0x12, 0x01, 0x21, 0x00, 0x4F, 0x05, 0x00 };
	const unsigned char INSTRUMENT_SYNSTR2[21]  = { 0x00, 0x21, 0x18, 0xC1, 0x22, 0x0C, 0x61, 0x00, 0x4F, 0x05, 0x00, 0x22, 0x0B, 0xC1, 0x22, 0x01, 0x22, 0x1C, 0x4F, 0x05, 0x00 };
	const unsigned char INSTRUMENT_CHOIR[21]    = { 0x00, 0x06, 0x03, 0xA0, 0xF5, 0x0E, 0xE4, 0x23, 0xA3, 0x35, 0x00, 0xA1, 0x51, 0x7F, 0x07, 0x01, 0x61, 0x00, 0x7F, 0x07, 0x00 };
	const unsigned char INSTRUMENT_OOHS[21]     = { 0x00, 0x02, 0x05, 0x84, 0x57, 0x0E, 0xE4, 0x16, 0xA7, 0x74, 0x00, 0xA1, 0x90, 0x74, 0x39, 0x01, 0x61, 0x00, 0x71, 0x67, 0x00 };
	const unsigned char INSTRUMENT_SYNVOX[21]   = { 0x00, 0x0A, 0x65, 0x99, 0x54, 0x08, 0x07, 0x60, 0x97, 0x63, 0x00, 0xA1, 0x59, 0x5F, 0x04, 0x00, 0x61, 0x00, 0x6F, 0x06, 0x01 };
	const unsigned char INSTRUMENT_ORCHIT[21]   = { 0x00, 0x00, 0x00, 0x65, 0x68, 0x0B, 0x00, 0x00, 0xC5, 0x13, 0x62, 0x00, 0x00, 0xC8, 0x06, 0x01, 0x00, 0x00, 0x74, 0x07, 0x36 };
	const unsigned char INSTRUMENT_TRUMPET[21]  = { 0x00, 0x21, 0x92, 0x85, 0x17, 0x0C, 0x21, 0x01, 0x8F, 0x09, 0x00, 0x21, 0x15, 0x84, 0x17, 0x01, 0x61, 0x0B, 0xAF, 0x08, 0x00 };
	const unsigned char INSTRUMENT_TROMBONE[21] = { 0x00, 0x21, 0x94, 0x85, 0x17, 0x0C, 0x21, 0x05, 0x7F, 0x09, 0x00, 0x21, 0x15, 0x84, 0x17, 0x01, 0x61, 0x0D, 0xAF, 0x08, 0x00 };
	const unsigned char INSTRUMENT_TUBA[21]     = { 0x00, 0x20, 0x94, 0x76, 0x15, 0x0C, 0x61, 0x00, 0x82, 0x37, 0x00, 0xB1, 0xD3, 0x61, 0x26, 0x01, 0x71, 0x80, 0x61, 0x26, 0x00 };
	const unsigned char INSTRUMENT_MUTETRP[21]  = { 0x00, 0x31, 0x15, 0x71, 0x27, 0x0C, 0x61, 0x83, 0x91, 0x49, 0x01, 0xB1, 0x10, 0x7D, 0x27, 0x01, 0x21, 0x08, 0x7A, 0x29, 0x00 };
	const unsigned char INSTRUMENT_FRHORN[21]   = { 0x00, 0x21, 0x9F, 0x63, 0x0A, 0x0E, 0x21, 0x00, 0x7F, 0x0B, 0x00, 0xA1, 0xA2, 0x65, 0x0A, 0x01, 0x61, 0x00, 0x7F, 0x0B, 0x00 };
	const unsigned char INSTRUMENT_BRASS1[21]   = { 0x00, 0x21, 0x16, 0x72, 0x25, 0x0C, 0x21, 0x05, 0x7F, 0x0A, 0x00, 0x21, 0x1D, 0x7A, 0x35, 0x01, 0x21, 0x09, 0x7A, 0x3A, 0x00 };
	const unsigned char INSTRUMENT_SYNBRAS1[21] = { 0x00, 0x21, 0x16, 0xC2, 0x35, 0x0E, 0x61, 0x09, 0xCF, 0x0A, 0x00, 0xA1, 0x8A, 0x74, 0x45, 0x01, 0x21, 0x00, 0x7F, 0x08, 0x00 };
	const unsigned char INSTRUMENT_SYNBRAS2[21] = { 0x00, 0xA1, 0x97, 0x52, 0x1A, 0x0C, 0x61, 0x00, 0x8F, 0x1B, 0x00, 0x21, 0xA1, 0x75, 0x1A, 0x01, 0x21, 0x00, 0x8F, 0x1B, 0x00 };
	const unsigned char INSTRUMENT_SOPSAX[21]   = { 0x00, 0x31, 0x96, 0x93, 0x0F, 0x08, 0xA1, 0x00, 0x72, 0x0F, 0x02, 0x21, 0x96, 0x85, 0x07, 0x01, 0x31, 0x00, 0x84, 0x27, 0x10 };
	const unsigned char INSTRUMENT_ALTOSAX[21]  = { 0x00, 0x31, 0x8E, 0x93, 0x03, 0x08, 0xA1, 0x00, 0x72, 0x09, 0x01, 0x24, 0xA1, 0xC5, 0x06, 0x01, 0x31, 0x00, 0x64, 0x27, 0x10 };
	const unsigned char INSTRUMENT_TENSAX[21]   = { 0x00, 0xB1, 0x8E, 0x93, 0x06, 0x0A, 0x71, 0x00, 0x72, 0x06, 0x01, 0x21, 0x5D, 0x85, 0x08, 0x01, 0xB1, 0x00, 0x84, 0x28, 0x00 };
	const unsigned char INSTRUMENT_BARISAX[21]  = { 0x00, 0x31, 0x93, 0x93, 0x0F, 0x0C, 0x72, 0x00, 0x72, 0x0F, 0x01, 0x22, 0x61, 0x85, 0x06, 0x01, 0xB1, 0x00, 0x84, 0x16, 0x00 };
	const unsigned char INSTRUMENT_OBOE[21]     = { 0x00, 0x61, 0xA3, 0xA9, 0x2A, 0x08, 0x23, 0x52, 0xA8, 0x36, 0x00, 0xA1, 0x94, 0xAA, 0x16, 0x00, 0x21, 0x80, 0x8F, 0x0A, 0x00 };
	const unsigned char INSTRUMENT_ENGLHORN[21] = { 0x00, 0x21, 0x21, 0x77, 0x29, 0x02, 0x33, 0x55, 0x7A, 0x26, 0x10, 0xA1, 0x93, 0x7A, 0x16, 0x00, 0x22, 0x00, 0x7A, 0x19, 0x00 };
	const unsigned char INSTRUMENT_BASSOON[21]  = { 0x00, 0x21, 0x2B, 0x7B, 0x07, 0x0A, 0x22, 0x57, 0x7F, 0x00, 0x01, 0x31, 0x51, 0x75, 0x19, 0x00, 0x72, 0x00, 0x61, 0x19, 0x00 };
	const unsigned char INSTRUMENT_CLARINET[21] = { 0x00, 0x32, 0x90, 0x9B, 0x21, 0x08, 0x21, 0x00, 0x72, 0x17, 0x00, 0x32, 0x90, 0x9B, 0x21, 0x01, 0x21, 0x13, 0x72, 0x17, 0x00 };
	const unsigned char INSTRUMENT_PICCOLO[21]  = { 0x00, 0x25, 0x00, 0xDA, 0x11, 0x0C, 0xE3, 0x2B, 0xA6, 0x68, 0x00, 0xE1, 0x1F, 0x85, 0x5F, 0x01, 0xE1, 0x00, 0x65, 0x1A, 0x00 };
	const unsigned char INSTRUMENT_FLUTE1[21]   = { 0x00, 0x25, 0x00, 0xDA, 0x11, 0x0C, 0xE3, 0x2B, 0xA6, 0x68, 0x00, 0xE1, 0x46, 0x88, 0x5F, 0x01, 0xE1, 0x00, 0x65, 0x1A, 0x00 };
	const unsigned char INSTRUMENT_RECORDER[21] = { 0x00, 0xA4, 0xA2, 0xC9, 0x29, 0x0C, 0x21, 0x80, 0x6F, 0x08, 0x00, 0xA2, 0xAA, 0xCA, 0x15, 0x01, 0x21, 0x00, 0x6F, 0x08, 0x00 };
	const unsigned char INSTRUMENT_PANFLUTE[21] = { 0x00, 0x25, 0x00, 0xDA, 0x11, 0x0C, 0x23, 0x1E, 0xA6, 0x68, 0x00, 0x21, 0x8C, 0x88, 0x58, 0x01, 0x21, 0x00, 0x65, 0x1A, 0x00 };
	const unsigned char INSTRUMENT_BOTTLEB[21]  = { 0x00, 0xA1, 0x0D, 0x76, 0xC6, 0x0F, 0x26, 0x59, 0x87, 0x86, 0x00, 0x22, 0x56, 0x66, 0x56, 0x00, 0xA1, 0x00, 0x65, 0x26, 0x00 };
	const unsigned char INSTRUMENT_SHAKU[21]    = { 0x00, 0x26, 0x00, 0x9F, 0x01, 0x0E, 0x64, 0x25, 0x76, 0x48, 0x00, 0x22, 0xCB, 0x56, 0x46, 0x01, 0xA1, 0x00, 0x45, 0x36, 0x00 };
	const unsigned char INSTRUMENT_WHISTLE[21]  = { 0x00, 0xE1, 0x67, 0x67, 0x14, 0x0C, 0x61, 0x00, 0x54, 0x17, 0x01, 0x21, 0x6D, 0x67, 0x14, 0x01, 0x21, 0x00, 0x44, 0x16, 0x01 };
	const unsigned char INSTRUMENT_OCARINA[21]  = { 0x00, 0x26, 0x00, 0xDF, 0x01, 0x0C, 0xE4, 0x2B, 0x76, 0x38, 0x00, 0x22, 0xD8, 0x95, 0x36, 0x01, 0xE1, 0x00, 0x76, 0x07, 0x00 };
	const unsigned char INSTRUMENT_SQUARWAV[21] = { 0x00, 0x21, 0x35, 0xFF, 0x0F, 0x04, 0x21, 0xB7, 0xFF, 0x0F, 0x00, 0x21, 0xB9, 0xFF, 0x0F, 0x00, 0x21, 0x80, 0xFF, 0x0F, 0x60 };
	const unsigned char INSTRUMENT_SAWWAV[21]   = { 0x00, 0x21, 0x36, 0xFF, 0x0F, 0x0A, 0x21, 0x1B, 0xFF, 0x0F, 0x00, 0x21, 0x1D, 0xFF, 0x0F, 0x00, 0x61, 0x00, 0xCF, 0x09, 0x40 };
	const unsigned char INSTRUMENT_SYNCALLI[21] = { 0x00, 0xA3, 0x00, 0xC4, 0x87, 0x0E, 0x26, 0x57, 0xC6, 0x76, 0x00, 0x22, 0x46, 0x86, 0x55, 0x01, 0x21, 0x80, 0x64, 0x18, 0x00 };
	const unsigned char INSTRUMENT_CHIFLEAD[21] = { 0x00, 0x21, 0x48, 0xA3, 0x4A, 0x08, 0x21, 0x00, 0x86, 0x0A, 0x00, 0x21, 0x45, 0x66, 0x12, 0x01, 0x21, 0x00, 0x96, 0x0A, 0x00 };
	const unsigned char INSTRUMENT_CHARANG[21]  = { 0x00, 0x12, 0x0D, 0xB9, 0xF2, 0x0A, 0x01, 0x1A, 0x91, 0x11, 0x04, 0x21, 0x99, 0x92, 0x2A, 0x00, 0x22, 0x00, 0x91, 0x2A, 0x01 };
	const unsigned char INSTRUMENT_SOLOVOX[21]  = { 0x00, 0x61, 0x40, 0x7D, 0x15, 0x0E, 0xB1, 0xA3, 0x72, 0x15, 0x00, 0xA2, 0x5D, 0xDF, 0x05, 0x01, 0x61, 0x40, 0x7F, 0x07, 0x00 };
	const unsigned char INSTRUMENT_FIFTHSAW[21] = { 0x00, 0x20, 0x36, 0xFF, 0x01, 0x08, 0x61, 0x00, 0x8F, 0x06, 0x40, 0x21, 0x27, 0xFF, 0x0F, 0x01, 0x61, 0x00, 0x8F, 0x07, 0x40 };
	const unsigned char INSTRUMENT_BASSLEAD[21] = { 0x00, 0x21, 0x8F, 0xF1, 0x29, 0x0A, 0x21, 0x80, 0xF4, 0x09, 0x00, 0x21, 0x1D, 0xF1, 0x09, 0x01, 0x21, 0x80, 0xF1, 0x09, 0x11 };
	const unsigned char INSTRUMENT_FANTASIA[21] = { 0x00, 0x17, 0x1A, 0x53, 0x03, 0x02, 0x08, 0x0D, 0xF6, 0x04, 0x01, 0xA1, 0x9D, 0x41, 0x32, 0x01, 0x61, 0x00, 0x61, 0x15, 0x00 };
	const unsigned char INSTRUMENT_WARMPAD[21]  = { 0x00, 0x61, 0x1F, 0xA8, 0x11, 0x0A, 0xB1, 0x80, 0x25, 0x03, 0x00, 0x81, 0xA1, 0xA1, 0x31, 0x01, 0x71, 0x00, 0x25, 0x03, 0x00 };
	const unsigned char INSTRUMENT_POLYSYN[21]  = { 0x00, 0x61, 0x17, 0x11, 0x14, 0x0C, 0x61, 0x00, 0x55, 0x16, 0x00, 0x61, 0x14, 0xC3, 0x45, 0x01, 0x61, 0x00, 0xC3, 0x25, 0x04 };
	const unsigned char INSTRUMENT_SPACEVOX[21] = { 0x00, 0x2A, 0x80, 0x54, 0x21, 0x0E, 0x27, 0xA6, 0x6A, 0x13, 0x00, 0x31, 0x5D, 0x54, 0x01, 0x01, 0x72, 0x00, 0x6A, 0x03, 0x00 };
	const unsigned char INSTRUMENT_BOWEDGLS[21] = { 0x00, 0x21, 0x97, 0x21, 0x33, 0x08, 0x22, 0x03, 0x42, 0x45, 0x00, 0xA1, 0x99, 0x21, 0xD4, 0x01, 0x21, 0x03, 0x42, 0xD5, 0x00 };
	const unsigned char INSTRUMENT_METALPAD[21] = { 0x00, 0x21, 0x8D, 0x61, 0x33, 0x0A, 0x61, 0x03, 0x42, 0x35, 0x00, 0xA1, 0x1C, 0xA1, 0x77, 0x01, 0x21, 0x00, 0x31, 0x47, 0x11 };
	const unsigned char INSTRUMENT_HALOPAD[21]  = { 0x00, 0x21, 0x89, 0x11, 0x33, 0x0A, 0x61, 0x03, 0x42, 0x35, 0x00, 0x21, 0x8C, 0x21, 0xE4, 0x01, 0x61, 0x03, 0x42, 0xD5, 0x00 };
	const unsigned char INSTRUMENT_SWEEPPAD[21] = { 0x00, 0x21, 0x15, 0x11, 0x47, 0x00, 0x21, 0x00, 0xCF, 0x07, 0x01, 0x21, 0x8C, 0x11, 0xE4, 0x01, 0x61, 0x00, 0x52, 0xD5, 0x00 };
	const unsigned char INSTRUMENT_ICERAIN[21]  = { 0x00, 0x0F, 0x83, 0xFE, 0x8A, 0x0C, 0x04, 0x85, 0xFB, 0x06, 0x05, 0x21, 0x99, 0xA8, 0x03, 0x01, 0x22, 0x00, 0xA7, 0x04, 0x00 };
	const unsigned char INSTRUMENT_SOUNDTRK[21] = { 0x00, 0x21, 0x8C, 0x21, 0x32, 0x06, 0x20, 0x97, 0x32, 0x13, 0x02, 0x21, 0x0E, 0x11, 0x03, 0x01, 0x21, 0x00, 0x31, 0x13, 0x01 };
	const unsigned char INSTRUMENT_CRYSTAL[21]  = { 0x00, 0x01, 0x61, 0x75, 0x93, 0x08, 0x02, 0x80, 0xC5, 0xB4, 0x00, 0x06, 0x5B, 0x74, 0x95, 0x01, 0x01, 0x00, 0xA5, 0x72, 0x00 };
	const unsigned char INSTRUMENT_ATMOSPH[21]  = { 0x00, 0x22, 0x92, 0xB2, 0x56, 0x0C, 0x61, 0x8A, 0xF2, 0x56, 0x00, 0x21, 0x9D, 0x31, 0x34, 0x01, 0xA1, 0x80, 0x32, 0x05, 0x02 };
	const unsigned char INSTRUMENT_BRIGHT[21]   = { 0x00, 0x24, 0x40, 0xA3, 0x88, 0x0E, 0x22, 0x5B, 0xA3, 0x87, 0x00, 0x01, 0x13, 0xF1, 0x51, 0x01, 0x41, 0x00, 0xF2, 0xF5, 0x01 };
	const unsigned char INSTRUMENT_GOBLIN[21]   = { 0x00, 0xA1, 0x10, 0x11, 0x42, 0x0A, 0x61, 0x92, 0x11, 0x73, 0x00, 0x61, 0x98, 0x11, 0x21, 0x01, 0xA1, 0x80, 0x1D, 0x03, 0x00 };
	const unsigned char INSTRUMENT_ECHODROP[21] = { 0x00, 0x62, 0x57, 0x7D, 0x16, 0x04, 0xA2, 0x80, 0x72, 0x16, 0x00, 0x61, 0x5B, 0x9F, 0x06, 0x01, 0xA1, 0x00, 0x9F, 0x04, 0x00 };
	const unsigned char INSTRUMENT_STARTHEM[21] = { 0x00, 0x38, 0x9F, 0xA2, 0x24, 0x06, 0x31, 0x9C, 0xF2, 0x24, 0x00, 0x23, 0x9F, 0xF1, 0x14, 0x00, 0x61, 0x00, 0x81, 0x23, 0x00 };
	const unsigned char INSTRUMENT_SITAR[21]    = { 0x00, 0x01, 0x46, 0xF3, 0x53, 0x00, 0x01, 0x80, 0xF1, 0xF6, 0x10, 0x01, 0x43, 0xF2, 0x53, 0x01, 0x08, 0x40, 0xF2, 0xF6, 0x00 };
	const unsigned char INSTRUMENT_BANJO[21]    = { 0x00, 0x11, 0x10, 0xA5, 0x35, 0x00, 0x17, 0xA4, 0xA5, 0x33, 0x11, 0x11, 0x0D, 0xF6, 0x41, 0x00, 0x11, 0x00, 0xF2, 0xE5, 0x21 };
	const unsigned char INSTRUMENT_SHAMISEN[21] = { 0x00, 0x55, 0x92, 0xF7, 0xF8, 0x0E, 0x52, 0x9F, 0xF7, 0xE4, 0x10, 0x41, 0x13, 0xF3, 0xE4, 0x00, 0x51, 0x00, 0xF3, 0xE5, 0x10 };
	const unsigned char INSTRUMENT_KOTO[21]     = { 0x00, 0x93, 0x91, 0xD4, 0x32, 0x08, 0x11, 0x00, 0xEB, 0x11, 0x10, 0x53, 0x91, 0xD4, 0x32, 0x01, 0x13, 0x0D, 0xEB, 0x12, 0x10 };
	const unsigned char INSTRUMENT_KALIMBA[21]  = { 0x00, 0x04, 0x4F, 0xFA, 0x56, 0x0C, 0x01, 0x00, 0xC2, 0x05, 0x00, 0x20, 0x00, 0xF7, 0xE5, 0x01, 0x21, 0x0C, 0xF5, 0xE5, 0x03 };
	const unsigned char INSTRUMENT_BAGPIPE[21]  = { 0x00, 0x21, 0x49, 0x7C, 0x20, 0x06, 0x22, 0x00, 0x6F, 0x0C, 0x10, 0x21, 0x09, 0x7C, 0x20, 0x01, 0x22, 0x09, 0x6F, 0x0C, 0x10 };
	const unsigned char INSTRUMENT_FIDDLE[21]   = { 0x00, 0x31, 0x85, 0xDD, 0x33, 0x0A, 0x21, 0x00, 0x56, 0x16, 0x01, 0x02, 0x83, 0xDD, 0x33, 0x01, 0x01, 0x80, 0x66, 0x16, 0x01 };
	const unsigned char INSTRUMENT_SHANNAI[21]  = { 0x00, 0x61, 0x33, 0x89, 0x29, 0x06, 0xA3, 0xA4, 0xD8, 0x06, 0x40, 0x21, 0x17, 0xDA, 0x05, 0x00, 0x22, 0x80, 0x8F, 0x0B, 0x00 };
	const unsigned char INSTRUMENT_TINKLBEL[21] = { 0x00, 0x05, 0x6A, 0xF1, 0xE5, 0x06, 0x03, 0x80, 0xC3, 0xE5, 0x00, 0x01, 0x71, 0xC6, 0x53, 0x01, 0x83, 0x40, 0xF5, 0xD5, 0x00 };
	const unsigned char INSTRUMENT_AGOGO[21]    = { 0x00, 0x08, 0x15, 0xEC, 0x26, 0x0A, 0x04, 0x00, 0xF8, 0x16, 0x00, 0x07, 0x15, 0xEC, 0x26, 0x01, 0x02, 0x00, 0xF8, 0x16, 0x00 };
	const unsigned char INSTRUMENT_STEELDRM[21] = { 0x00, 0x2C, 0xAB, 0x68, 0x24, 0x00, 0x01, 0x00, 0xDF, 0x35, 0x00, 0x05, 0x9D, 0x67, 0x35, 0x01, 0x01, 0x00, 0xDF, 0x05, 0x00 };
	const unsigned char INSTRUMENT_WOODBLOK[21] = { 0x00, 0x15, 0x11, 0xFA, 0xFC, 0x0A, 0x12, 0x80, 0xFA, 0xEC, 0x04, 0x18, 0x9D, 0xFA, 0xFC, 0x01, 0x12, 0x00, 0xF8, 0xE5, 0x00 };
	const unsigned char INSTRUMENT_TAIKO[21]    = { 0x00, 0x10, 0x86, 0xA8, 0x07, 0x06, 0x00, 0x03, 0xFA, 0x03, 0x00, 0x01, 0x5C, 0xA8, 0x07, 0x01, 0x00, 0x03, 0xF6, 0x83, 0x00 };
	const unsigned char INSTRUMENT_MELOTOM[21]  = { 0x00, 0x11, 0x8F, 0xF8, 0x58, 0x0E, 0x10, 0x00, 0xF3, 0xE5, 0x04, 0x10, 0x92, 0xF6, 0x54, 0x01, 0x10, 0x00, 0xF4, 0xE4, 0x01 };
	const unsigned char INSTRUMENT_SYNDRUM[21]  = { 0x00, 0x11, 0x86, 0xF8, 0x55, 0x0E, 0x10, 0x00, 0xF4, 0xE5, 0x04, 0x11, 0x9C, 0xF3, 0x55, 0x01, 0x10, 0x00, 0xF4, 0xE5, 0x01 };
	const unsigned char INSTRUMENT_REVRSCYM[21] = { 0x00, 0x0F, 0x00, 0x1F, 0x00, 0x0E, 0xC0, 0x00, 0x1F, 0xF0, 0x30, 0x0F, 0x3F, 0x1F, 0x00, 0x01, 0xC0, 0x3F, 0x1F, 0xF1, 0x30 };
	const unsigned char INSTRUMENT_FRETNOIS[21] = { 0x00, 0x06, 0x80, 0xF8, 0x24, 0x0E, 0x03, 0x88, 0x56, 0x84, 0x70, 0x03, 0x1E, 0xD8, 0x24, 0x01, 0x04, 0x08, 0x66, 0x84, 0x70 };
	const unsigned char INSTRUMENT_BRTHNOIS[21] = { 0x00, 0x06, 0x00, 0xFF, 0x01, 0x0E, 0x14, 0x00, 0x34, 0x04, 0x30, 0x01, 0x3F, 0x00, 0xF1, 0x01, 0x01, 0x3F, 0x00, 0xF1, 0x00 };
	const unsigned char INSTRUMENT_SEASHORE[21] = { 0x00, 0x26, 0x00, 0xFF, 0x01, 0x0E, 0x04, 0x00, 0x12, 0x84, 0x10, 0x01, 0x3F, 0x00, 0xF1, 0x01, 0x01, 0x3F, 0x00, 0xF1, 0x00 };
	const unsigned char INSTRUMENT_BIRDS[21]    = { 0x00, 0x48, 0x00, 0x68, 0xF8, 0x05, 0x01, 0x3F, 0x00, 0xF1, 0x00, 0x47, 0x00, 0x67, 0xF8, 0x01, 0x4C, 0x00, 0x46, 0xF8, 0x00 };
	const unsigned char INSTRUMENT_TELEPHON[21] = { 0x00, 0x35, 0x1C, 0xB2, 0x61, 0x0A, 0x14, 0x08, 0xF4, 0x15, 0x02, 0x11, 0x20, 0xFE, 0x15, 0x01, 0x87, 0xC0, 0xF4, 0x19, 0x07 };
	const unsigned char INSTRUMENT_HELICOPT[21] = { 0x00, 0xF0, 0x00, 0x2E, 0x11, 0x08, 0xE2, 0xC0, 0x21, 0x16, 0x11, 0xF0, 0x00, 0x2E, 0x11, 0x01, 0xE2, 0xC0, 0x21, 0x16, 0x17 };
	const unsigned char INSTRUMENT_APPLAUSE[21] = { 0x00, 0x26, 0x00, 0xFF, 0x01, 0x0E, 0xE4, 0x00, 0x12, 0x16, 0x70, 0x01, 0x3F, 0x00, 0xF1, 0x01, 0x01, 0x3F, 0x00, 0xF1, 0x00 };
	const unsigned char INSTRUMENT_GUNSHOT[21]  = { 0x00, 0x00, 0x00, 0xF2, 0x59, 0x0E, 0x01, 0x00, 0xF7, 0x00, 0x00, 0x01, 0x00, 0xF3, 0xF0, 0x00, 0x01, 0x00, 0xF6, 0xC9, 0x60 };


	// Instrument pointer array to access instruments by MIDI program.
	const unsigned char *midiInstruments[] = {
		INSTRUMENT_PIANO1,   INSTRUMENT_PIANO2,   INSTRUMENT_PIANO3,   INSTRUMENT_HONKTONK, INSTRUMENT_EP1,      INSTRUMENT_EP2,
		INSTRUMENT_HARPSIC,  INSTRUMENT_CLAVIC,   INSTRUMENT_CELESTA,  INSTRUMENT_GLOCK,    INSTRUMENT_MUSICBOX, INSTRUMENT_VIBES,
		INSTRUMENT_MARIMBA,  INSTRUMENT_XYLO,     INSTRUMENT_TUBEBELL, INSTRUMENT_SANTUR,   INSTRUMENT_ORGAN1,   INSTRUMENT_ORGAN2,
		INSTRUMENT_ORGAN3,   INSTRUMENT_PIPEORG,  INSTRUMENT_REEDORG,  INSTRUMENT_ACORDIAN, INSTRUMENT_HARMONIC, INSTRUMENT_BANDNEON,
		INSTRUMENT_NYLONGT,  INSTRUMENT_STEELGT,  INSTRUMENT_JAZZGT,   INSTRUMENT_CLEANGT,  INSTRUMENT_MUTEGT,   INSTRUMENT_OVERDGT,
		INSTRUMENT_DISTGT,   INSTRUMENT_GTHARMS,  INSTRUMENT_ACOUBASS, INSTRUMENT_FINGBASS, INSTRUMENT_PICKBASS, INSTRUMENT_FRETLESS,
		INSTRUMENT_SLAPBAS1, INSTRUMENT_SLAPBAS2, INSTRUMENT_SYNBASS1, INSTRUMENT_SYNBASS2, INSTRUMENT_VIOLIN,   INSTRUMENT_VIOLA,
		INSTRUMENT_CELLO,    INSTRUMENT_CONTRAB,  INSTRUMENT_TREMSTR,  INSTRUMENT_PIZZ,     INSTRUMENT_HARP,     INSTRUMENT_TIMPANI,
		INSTRUMENT_STRINGS,  INSTRUMENT_SLOWSTR,  INSTRUMENT_SYNSTR1,  INSTRUMENT_SYNSTR2,  INSTRUMENT_CHOIR,    INSTRUMENT_OOHS,
		INSTRUMENT_SYNVOX,   INSTRUMENT_ORCHIT,   INSTRUMENT_TRUMPET,  INSTRUMENT_TROMBONE, INSTRUMENT_TUBA,     INSTRUMENT_MUTETRP,
		INSTRUMENT_FRHORN,   INSTRUMENT_BRASS1,   INSTRUMENT_SYNBRAS1, INSTRUMENT_SYNBRAS2, INSTRUMENT_SOPSAX,   INSTRUMENT_ALTOSAX,
		INSTRUMENT_TENSAX,   INSTRUMENT_BARISAX,  INSTRUMENT_OBOE,     INSTRUMENT_ENGLHORN, INSTRUMENT_BASSOON,  INSTRUMENT_CLARINET,
		INSTRUMENT_PICCOLO,  INSTRUMENT_FLUTE1,   INSTRUMENT_RECORDER, INSTRUMENT_PANFLUTE, INSTRUMENT_BOTTLEB,  INSTRUMENT_SHAKU,
		INSTRUMENT_WHISTLE,  INSTRUMENT_OCARINA,  INSTRUMENT_SQUARWAV, INSTRUMENT_SAWWAV,   INSTRUMENT_SYNCALLI, INSTRUMENT_CHIFLEAD,
		INSTRUMENT_CHARANG,  INSTRUMENT_SOLOVOX,  INSTRUMENT_FIFTHSAW, INSTRUMENT_BASSLEAD, INSTRUMENT_FANTASIA, INSTRUMENT_WARMPAD,
		INSTRUMENT_POLYSYN,  INSTRUMENT_SPACEVOX, INSTRUMENT_BOWEDGLS, INSTRUMENT_METALPAD, INSTRUMENT_HALOPAD,  INSTRUMENT_SWEEPPAD,
		INSTRUMENT_ICERAIN,  INSTRUMENT_SOUNDTRK, INSTRUMENT_CRYSTAL,  INSTRUMENT_ATMOSPH,  INSTRUMENT_BRIGHT,   INSTRUMENT_GOBLIN,
		INSTRUMENT_ECHODROP, INSTRUMENT_STARTHEM, INSTRUMENT_SITAR,    INSTRUMENT_BANJO,    INSTRUMENT_SHAMISEN, INSTRUMENT_KOTO,
		INSTRUMENT_KALIMBA,  INSTRUMENT_BAGPIPE,  INSTRUMENT_FIDDLE,   INSTRUMENT_SHANNAI,  INSTRUMENT_TINKLBEL, INSTRUMENT_AGOGO,
		INSTRUMENT_STEELDRM, INSTRUMENT_WOODBLOK, INSTRUMENT_TAIKO,    INSTRUMENT_MELOTOM,  INSTRUMENT_SYNDRUM,  INSTRUMENT_REVRSCYM,
		INSTRUMENT_FRETNOIS, INSTRUMENT_BRTHNOIS, INSTRUMENT_SEASHORE, INSTRUMENT_BIRDS,    INSTRUMENT_TELEPHON, INSTRUMENT_HELICOPT,
		INSTRUMENT_APPLAUSE, INSTRUMENT_GUNSHOT
	};

#endif