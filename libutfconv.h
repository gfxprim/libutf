// SPDX-License-Identifier: LGPL-2.1-or-later
/*
 * Copyright (C) 2023 Cyril Hrubis <metan@ucw.cz>
 */

/*
 * Minimalistic encoding conversion library.
 */

#ifndef LIB_UTF_CONV_H
#define LIB_UTF_CONV_H

#include <stdint.h>
#include <stddef.h>

#include "libutf8.h"

extern uint16_t lu_cp1250_utf[];
extern uint16_t lu_cp1251_utf[];
extern uint16_t lu_cp1252_utf[];
extern uint16_t lu_cp1253_utf[];
extern uint16_t lu_cp1254_utf[];
extern uint16_t lu_cp1255_utf[];
extern uint16_t lu_cp1256_utf[];
extern uint16_t lu_cp1257_utf[];
extern uint16_t lu_cp1258_utf[];

static inline uint16_t lu_cp1250_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1250_utf[cp-0x80];
}

static inline uint16_t lu_cp1251_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1251_utf[cp-0x80];
}

static inline uint16_t lu_cp1252_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1252_utf[cp-0x80];
}

static inline uint16_t lu_cp1253_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1253_utf[cp-0x80];
}

static inline uint16_t lu_cp1254_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1254_utf[cp-0x80];
}

static inline uint16_t lu_cp1255_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1255_utf[cp-0x80];
}

static inline uint16_t lu_cp1256_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1256_utf[cp-0x80];
}

static inline uint16_t lu_cp1257_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1257_utf[cp-0x80];
}

static inline uint16_t lu_cp1258_to_utf(uint8_t cp)
{
	if (cp < 0x80)
		return cp;

	return lu_cp1258_utf[cp-0x80];
}

enum lu_enc {
	LU_NONE,   /* Do not decode anything */
	LU_CP1250, /* Central Europe */
	LU_CP1251, /* Cyrilic */
	LU_CP1252, /* Western Europe */
	LU_CP1253, /* Greek */
	LU_CP1254, /* Turkish */
	LU_CP1255, /* Hebrew */
	LU_CP1256, /* Arabic */
	LU_CP1257, /* Baltic */
	LU_CP1258, /* Vietnamese */
	LU_ENC_CNT,
	LU_ENC_ERR=LU_ENC_CNT,
};

/**
 * @brief Looks up for encoding by a name.
 *
 * @enc_name An encoding name e.g. "cp1250"
 * @return An encoding type or LU_ENC_ERR if no match was found.
 */
enum lu_enc lu_name_to_enc(const char *enc_name);

/**
 * @brief Returns encoding name.
 *
 * @enc An encoding id.
 * @return An encoding name.
 */
const char *lu_enc_to_name(enum lu_enc enc);

/**
 * @brief Converts a single character into unicode.
 *
 * @enc Input encoding.
 * @cp Input character.
 * @return An unicode character or zero if there is no mapping.
 */
static inline uint16_t lu_to_utf(uint8_t cp, enum lu_enc enc)
{
	switch (enc) {
	case LU_NONE:
		return cp;
	case LU_CP1250:
		return lu_cp1250_to_utf(cp);
	case LU_CP1251:
		return lu_cp1251_to_utf(cp);
	case LU_CP1252:
		return lu_cp1252_to_utf(cp);
	case LU_CP1253:
		return lu_cp1253_to_utf(cp);
	case LU_CP1254:
		return lu_cp1254_to_utf(cp);
	case LU_CP1255:
		return lu_cp1255_to_utf(cp);
	case LU_CP1256:
		return lu_cp1256_to_utf(cp);
	case LU_CP1257:
		return lu_cp1257_to_utf(cp);
	case LU_CP1258:
		return lu_cp1258_to_utf(cp);
	default:
		return 0;
	}
}

/**
 * @brief Returns number of bytes needed for a character after utf8 conversion.
 *
 * @enc An encoding.
 * @cp A character.
 *
 * @return A number of bytes needed for the character in utf8.
 */
static inline uint8_t lu_to_utf8_bytes(uint8_t cp, enum lu_enc enc)
{
	return lu_utf8_bytes(lu_to_utf(cp, enc));
}

/**
 * @brief Counts number of bytes needed for a string after conversion to utf8.
 *
 * @str A string.
 * @enc An encoding the string is encoded in.
 *
 * @return A number of bytes including space for the null terminating byte.
 */
size_t lu_to_utf8_size(const char *str, enum lu_enc enc);

/**
 * @brief Converts a string into utf8.
 *
 * @str A source string.
 * @dst A destination, the destination must be large enough, see lu_utf8_len().
 */
void lu_to_utf8_cpy(const char *src, char *dest, enum lu_enc enc);


/**
 * @brief Returns newly allocated buffer with a string converted into utf8.
 *
 * @str A string.
 * @enc An encoding the string is encoded in.
 *
 * @return Newly allocated buffer with converted string.
 */
char *lu_to_utf8_alloc(const char *src, enum lu_enc enc);

#endif /* LIB_UTF_CONV_H */
