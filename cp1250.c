// SPDX-License-Identifier: LGPL-2.1-or-later
/*
 * Copyright (C) 2023 Cyril Hrubis <metan@ucw.cz>
 */

#include "libutfconv.h"

uint16_t lu_cp1250_utf[0x80] = {
	[0] = 0x20AC,
	/* 1 undef */
	[2] = 0x201A,
	/* 3 undef */
	[4] = 0x201E,
	[5] = 0x2026,
	[6] = 0x2020,
	[7] = 0x2021,
	/* 8 undef */
	[9] = 0x2030,
	[10] = 0x0160,
	[11] = 0x2039,
	[12] = 0x015A,
	[13] = 0x0164,
	[14] = 0x017D,
	[15] = 0x0179,
	/* 16 undef */
	[17] = 0x2018,
	[18] = 0x2019,
	[19] = 0x201C,
	[20] = 0x201D,
	[21] = 0x2022,
	[22] = 0x2013,
	[23] = 0x2014,
	/* 24 undef */
	[25] = 0x2122,
	[26] = 0x0161,
	[27] = 0x203A,
	[28] = 0x015B,
	[29] = 0x0165,
	[30] = 0x017E,
	[31] = 0x017A,
	[32] = 0x00A0,
	[33] = 0x02C7,
	[34] = 0x02D8,
	[35] = 0x0141,
	[36] = 0x00A4,
	[37] = 0x0104,
	[38] = 0x00A6,
	[39] = 0x00A7,
	[40] = 0x00A8,
	[41] = 0x00A9,
	[42] = 0x015E,
	[43] = 0x00AB,
	[44] = 0x00AC,
	[45] = 0x00AD,
	[46] = 0x00AE,
	[47] = 0x017B,
	[48] = 0x00B0,
	[49] = 0x00B1,
	[50] = 0x02DB,
	[51] = 0x0142,
	[52] = 0x00B4,
	[53] = 0x00B5,
	[54] = 0x00B6,
	[55] = 0x00B7,
	[56] = 0x00B8,
	[57] = 0x0105,
	[58] = 0x015F,
	[59] = 0x00BB,
	[60] = 0x013D,
	[61] = 0x02DD,
	[62] = 0x013E,
	[63] = 0x017C,
	[64] = 0x0154,
	[65] = 0x00C1,
	[66] = 0x00C2,
	[67] = 0x0102,
	[68] = 0x00C4,
	[69] = 0x0139,
	[70] = 0x0106,
	[71] = 0x00C7,
	[72] = 0x010C,
	[73] = 0x00C9,
	[74] = 0x0118,
	[75] = 0x00CB,
	[76] = 0x011A,
	[77] = 0x00CD,
	[78] = 0x00CE,
	[79] = 0x010E,
	[80] = 0x0110,
	[81] = 0x0143,
	[82] = 0x0147,
	[83] = 0x00D3,
	[84] = 0x00D4,
	[85] = 0x0150,
	[86] = 0x00D6,
	[87] = 0x00D7,
	[88] = 0x0158,
	[89] = 0x016E,
	[90] = 0x00DA,
	[91] = 0x0170,
	[92] = 0x00DC,
	[93] = 0x00DD,
	[94] = 0x0162,
	[95] = 0x00DF,
	[96] = 0x0155,
	[97] = 0x00E1,
	[98] = 0x00E2,
	[99] = 0x0103,
	[100] = 0x00E4,
	[101] = 0x013A,
	[102] = 0x0107,
	[103] = 0x00E7,
	[104] = 0x010D,
	[105] = 0x00E9,
	[106] = 0x0119,
	[107] = 0x00EB,
	[108] = 0x011B,
	[109] = 0x00ED,
	[110] = 0x00EE,
	[111] = 0x010F,
	[112] = 0x0111,
	[113] = 0x0144,
	[114] = 0x0148,
	[115] = 0x00F3,
	[116] = 0x00F4,
	[117] = 0x0151,
	[118] = 0x00F6,
	[119] = 0x00F7,
	[120] = 0x0159,
	[121] = 0x016F,
	[122] = 0x00FA,
	[123] = 0x0171,
	[124] = 0x00FC,
	[125] = 0x00FD,
	[126] = 0x0163,
	[127] = 0x02D9,
};