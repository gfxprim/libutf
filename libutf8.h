// SPDX-License-Identifier: LGPL-2.1-or-later
/*
 * Copyright (C) 2023 Cyril Hrubis <metan@ucw.cz>
 */

#ifndef LIB_UTF_ENC_H
#define LIB_UTF_ENC_H

#include <stdint.h>

#define LU_UTF8_IS_ASCII(ch) (!((ch) & 0x80))
#define LU_UTF8_IS_NBYTE(ch) (((ch) & 0xc0) == 0x80)
#define LU_UTF8_IS_2BYTE(ch) (((ch) & 0xe0) == 0xc0)
#define LU_UTF8_IS_3BYTE(ch) (((ch) & 0xf0) == 0xe0)
#define LU_UTF8_IS_4BYTE(ch) (((ch) & 0xf8) == 0xf0)

#define LU_UTF8_NBYTE_MASK 0x3f

/**
 * @brief: Returns glyphs in UTF8 string one at a time
 *
 * @str An UTF8 string
 * @return An UTF8 glyph or 0 on error or end of string.
 */
static inline uint32_t lu_utf8_next(const char **str)
{
	uint32_t s0 = *str[0];

	(*str)++;

	if (LU_UTF8_IS_ASCII(s0))
		return s0;

	uint32_t s1 = *str[0];

	if (!LU_UTF8_IS_NBYTE(s1))
		return 0;

	s1 &= LU_UTF8_NBYTE_MASK;

	(*str)++;

	if (LU_UTF8_IS_2BYTE(s0))
		return (s0 & 0x1f)<<6 | s1;

	uint32_t s2 = *str[0];

	if (!LU_UTF8_IS_NBYTE(s2))
		return 0;

	s2 &= LU_UTF8_NBYTE_MASK;

	(*str)++;

	if (LU_UTF8_IS_3BYTE(s0))
		return (s0 & 0x0f)<<12 | s1<<6 | s2;

	(*str)++;

	uint32_t s3 = *str[0];

	if (!LU_UTF8_IS_NBYTE(s2))
		return 0;

	s3 &= LU_UTF8_NBYTE_MASK;

	if (LU_UTF8_IS_4BYTE(s0))
		return (s0 & 0x07)<<18 | s1<<12 | s2<<6 | s3;

	return 0;
}

/**
 * @unicode A unicode character.
 * @return Number of utf8 bytes required to store a unicode character.
 */
static inline unsigned int lu_utf8_bytes(uint32_t unicode)
{
	if (unicode < 0x0080)
		return 1;

	if (unicode < 0x0800)
		return 2;

	if (unicode < 0x10000)
		return 3;

	return 4;
}

/**
 * Writes an unicode characters into a byte buffer.
 *
 * The buffer _must_ be large enough!
 *
 * @unicode A unicode character.
 * @buf A byte buffer.
 * @return A number of bytes written.
 */
static inline int lu_to_utf8(uint32_t unicode, char *buf)
{
	if (unicode < 0x0080) {
		buf[0] = unicode & 0x007f;
		return 1;
	}

	if (unicode < 0x0800) {
		buf[0] = 0xc0 | (0x1f & (unicode>>6));
		buf[1] = 0x80 | (0x3f & unicode);
		return 2;
	}

	if (unicode < 0x10000) {
		buf[0] = 0xe0 | (0x0f & (unicode>>12));
		buf[1] = 0x80 | (0x3f & (unicode>>6));
		buf[2] = 0x80 | (0x3f & unicode);
		return 3;
	}

	buf[0] = 0xf0 | (0x07 & (unicode>>18));
	buf[1] = 0x80 | (0x3f & (unicode>>12));
	buf[2] = 0x80 | (0x3f & (unicode>>6));
	buf[3] = 0x80 | (0x3f & unicode);
	return 4;
}

#endif /* LIB_UTF_ENC_H */
