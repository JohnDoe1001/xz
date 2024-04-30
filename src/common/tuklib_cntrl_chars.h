// SPDX-License-Identifier: 0BSD

///////////////////////////////////////////////////////////////////////////////
//
/// \file       tuklib_cntrl_chars.h
/// \brief      Find and replace single-byte control characters
///
/// This is a small and very simple implementation that uses isnctrl(3),
/// that is, this works on individual bytes. Multibyte control characters
/// aren't handled. These functions should still help a lot because they
/// catch US-ASCII control characters in C and UTF-8 locales.
//
//  Author:     Lasse Collin
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TUKLIB_CNTRL_CHARS_H
#define TUKLIB_CNTRL_CHARS_H

#include "tuklib_common.h"
TUKLIB_DECLS_BEGIN

#define tuklib_has_cntrl TUKLIB_SYMBOL(tuklib_has_cntrl)
extern bool tuklib_has_cntrl(const char *str);
///<
/// \brief      Check if a string contains single-byte control characters
///
/// \brief      false if iscntrl() returns zero on all bytes in str.
///             Otherwise true is returned.

#define tuklib_mask_cntrl TUKLIB_SYMBOL(tuklib_mask_cntrl)
extern const char *tuklib_mask_cntrl(const char *str);
///<
/// \brief      Mask single-byte control characters in an untrusted string
///
/// \param      str     Untrusted string, for example, a filename
///
/// \return     If has_cntrl_chars(str) returns false, this function returns
///             str. Otherwise memory is allocated to hold a modified string
///             and a pointer to that is returned. This function remembers
///             the pointers in a static variable. This means that each call
///             to this function makes the old return values invalid, and that
///             this function isn't thread safe (it doesn't use a thread-local
///             variable). A modified string has the problematic bytes
///             replaced by '?'. If memory allocation fails, "???" is returned.

TUKLIB_DECLS_END
#endif
