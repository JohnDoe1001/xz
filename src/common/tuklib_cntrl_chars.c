// SPDX-License-Identifier: 0BSD

///////////////////////////////////////////////////////////////////////////////
//
/// \file       tuklib_cntrl_chars.c
/// \brief      Find and replace single-byte control characters
//
//  Author:     Lasse Collin
//
///////////////////////////////////////////////////////////////////////////////

#include "tuklib_cntrl_chars.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// strdup() is in SUSv2 and C23. MSVC has it as _strdup().
#if defined(_MSC_VER) && !defined(strdup)
#	define strdup _strdup
#endif


extern bool
tuklib_has_cntrl(const char *str)
{
	for (size_t i = 0; str[i] != '\0'; ++i)
		if (iscntrl((unsigned char)str[i]))
			return true;

	return false;
}


extern const char *
tuklib_mask_cntrl(const char *str)
{
	static char *mem = NULL;

	// Free the old string, if any.
	free(mem);
	mem = NULL;

	// If there are no control chars, return the input string.
	if (!tuklib_has_cntrl(str))
		return str;

	// Allocate a copy of the string. If allocation fails, return "???"
	// because it should be safer than returning the unmasked string.
	mem = strdup(str);
	if (mem == NULL)
		return "???";

	// Replace all single-byte control characters with '?'.
	for (size_t i = 0; mem[i] != '\0'; ++i)
		if (iscntrl((unsigned char)mem[i]))
			mem[i] = '?';

	return mem;
}
