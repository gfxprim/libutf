// SPDX-License-Identifier: LGPL-2.1-or-later
/*
 * Copyright (C) 2023 Cyril Hrubis <metan@ucw.cz>
 */

/*
 * Uppercase/lowercase conversions.
 */

#ifndef LIB_UTF_CASE_H
#define LIB_UTF_CASE_H

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Simple unicode casefolding function.
 *
 * Returns either mapping to a lovercase character or if there is no mapping or
 * character is already lovercase the input codepoint.
 *
 * This is a simple function that returns single codepoint, which is generally
 * not optimal solution in certain cases such as german sharp s that casefolds
 * to 'ss'.
 *
 * @cp An unicode codepoint to be casefolded.
 * @return A casefolded character.
 */
uint32_t lu_casefold_simple(uint32_t cp);

/**
 * @brief Unicode casefolding function.
 *
 * Returns either mapping to a lovercase character or if there is no mapping or
 * character is already lovercase the input codepoint.
 *
 * Returns up to three characters, e.g. for ffi ligature.
 *
 * @cp An unicode codepoint to be casefolded.
 * @res An array to put the result into, has to be at least three 32bit uints long.
 * @return Number of characters that has been written to res.
 */
int lu_casefold(uint32_t cp, uint32_t *res);

#endif /* LIB_UTF_CASE_H */
