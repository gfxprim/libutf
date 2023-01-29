// SPDX-License-Identifier: LGPL-2.1-or-later
/*
 * Copyright (C) 2023 Cyril Hrubis <metan@ucw.cz>
 */

#include <string.h>
#include <stdlib.h>
#include "libutfconv.h"

static const char *enc_names[LU_ENC_CNT] = {
	"none",
	"cp1250",
	"cp1251",
	"cp1252",
	"cp1253",
	"cp1254",
	"cp1255",
	"cp1256",
	"cp1257",
	"cp1258",
};

enum lu_enc lu_name_to_enc(const char *enc_name)
{
	unsigned int i;

	for (i = 0; i < LU_ENC_CNT; i++) {
		if (!strcasecmp(enc_name, enc_names[i]))
			return i;
	}

	return LU_ENC_ERR;
}

const char *lu_enc_to_name(enum lu_enc enc)
{
	if (enc >= LU_ENC_CNT)
		return "invalid";

	return enc_names[enc];
}

size_t lu_to_utf8_size(const char *str, enum lu_enc enc)
{
	size_t len = 1;

	while (*str) {
		len += lu_to_utf8_bytes(enc, *str);
		str++;
	}

	return len;
}

void lu_to_utf8_cpy(const char *src, char *dest, enum lu_enc enc)
{
	while (*src) {
		uint32_t utf = lu_to_utf(*src, enc);
		dest += lu_to_utf8(utf, dest);
		src++;
	}
}

char *lu_to_utf8_alloc(const char *src, enum lu_enc enc)
{
	char *ret = malloc(lu_to_utf8_size(src, enc));

	if (!ret)
		return NULL;

	while (*src)
		ret += lu_to_utf8(lu_to_utf(*(src++), enc), ret);

	*ret = 0;

	return ret;
}
