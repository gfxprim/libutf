// SPDX-License-Identifier: LGPL-2.1-or-later
/*
 * Copyright (C) 2023 Cyril Hrubis <metan@ucw.cz>
 */

#include "libutfconv.h"

uint16_t lu_cp1255_utf[0x80] = {
	[0] = 0x20AC,
	/* 1 undef */
	[2] = 0x201A,
	[3] = 0x0192,
	[4] = 0x201E,
	[5] = 0x2026,
	[6] = 0x2020,
	[7] = 0x2021,
	[8] = 0x02C6,
	[9] = 0x2030,
	/* 10 undef */
	[11] = 0x2039,
	/* 12 undef */
	/* 13 undef */
	/* 14 undef */
	/* 15 undef */
	/* 16 undef */
	[17] = 0x2018,
	[18] = 0x2019,
	[19] = 0x201C,
	[20] = 0x201D,
	[21] = 0x2022,
	[22] = 0x2013,
	[23] = 0x2014,
	[24] = 0x02DC,
	[25] = 0x2122,
	/* 26 undef */
	[27] = 0x203A,
	/* 28 undef */
	/* 29 undef */
	/* 30 undef */
	/* 31 undef */
	[32] = 0x00A0,
	[33] = 0x00A1,
	[34] = 0x00A2,
	[35] = 0x00A3,
	[36] = 0x20AA,
	[37] = 0x00A5,
	[38] = 0x00A6,
	[39] = 0x00A7,
	[40] = 0x00A8,
	[41] = 0x00A9,
	[42] = 0x00D7,
	[43] = 0x00AB,
	[44] = 0x00AC,
	[45] = 0x00AD,
	[46] = 0x00AE,
	[47] = 0x00AF,
	[48] = 0x00B0,
	[49] = 0x00B1,
	[50] = 0x00B2,
	[51] = 0x00B3,
	[52] = 0x00B4,
	[53] = 0x00B5,
	[54] = 0x00B6,
	[55] = 0x00B7,
	[56] = 0x00B8,
	[57] = 0x00B9,
	[58] = 0x00F7,
	[59] = 0x00BB,
	[60] = 0x00BC,
	[61] = 0x00BD,
	[62] = 0x00BE,
	[63] = 0x00BF,
	[64] = 0x05B0,
	[65] = 0x05B1,
	[66] = 0x05B2,
	[67] = 0x05B3,
	[68] = 0x05B4,
	[69] = 0x05B5,
	[70] = 0x05B6,
	[71] = 0x05B7,
	[72] = 0x05B8,
	[73] = 0x05B9,
	/* 74 undef */
	[75] = 0x05BB,
	[76] = 0x05BC,
	[77] = 0x05BD,
	[78] = 0x05BE,
	[79] = 0x05BF,
	[80] = 0x05C0,
	[81] = 0x05C1,
	[82] = 0x05C2,
	[83] = 0x05C3,
	[84] = 0x05F0,
	[85] = 0x05F1,
	[86] = 0x05F2,
	[87] = 0x05F3,
	[88] = 0x05F4,
	/* 89 undef */
	/* 90 undef */
	/* 91 undef */
	/* 92 undef */
	/* 93 undef */
	/* 94 undef */
	/* 95 undef */
	[96] = 0x05D0,
	[97] = 0x05D1,
	[98] = 0x05D2,
	[99] = 0x05D3,
	[100] = 0x05D4,
	[101] = 0x05D5,
	[102] = 0x05D6,
	[103] = 0x05D7,
	[104] = 0x05D8,
	[105] = 0x05D9,
	[106] = 0x05DA,
	[107] = 0x05DB,
	[108] = 0x05DC,
	[109] = 0x05DD,
	[110] = 0x05DE,
	[111] = 0x05DF,
	[112] = 0x05E0,
	[113] = 0x05E1,
	[114] = 0x05E2,
	[115] = 0x05E3,
	[116] = 0x05E4,
	[117] = 0x05E5,
	[118] = 0x05E6,
	[119] = 0x05E7,
	[120] = 0x05E8,
	[121] = 0x05E9,
	[122] = 0x05EA,
	/* 123 undef */
	/* 124 undef */
	[125] = 0x200E,
	[126] = 0x200F,
	/* 127 undef */
};