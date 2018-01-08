/*
 * Copyright(C) 2007, 2013 Renesas Electronics Corporation
 * RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
 * This program must be used solely for the purpose for which
 * it was furnished by Renesas Electronics Corporation. No part of this
 * program may be reproduced or disclosed to others, in any
 * form, without the prior written permission of Renesas Electronics
 * Corporation.
 */

/********************************************************************************/
/* RX Family C/C++ Compiler                                                     */
/********************************************************************************/

/* wctype.h standard header */
#ifndef _WCTYPE
#define _WCTYPE
#include <macro.h>
#ifndef _YVALS
#include <sys/yvals.h>
#endif /* _YVALS */

_C_STD_BEGIN

		/* MACROS */
#define WEOF	((_CSTD wint_t)(-1))

		/* TYPE DEFINITIONS */
typedef _Sizet wctrans_t;

typedef _Sizet wctype_t;

 #ifndef _WINTT
  #define _WINTT
typedef _Wintt wint_t;
 #endif /* _WINTT */

		/* ctype DECLARATIONS */
#include <sys/xwcc.h>

_C_LIB_DECL
wctrans_t wctrans(const char *);
wctype_t wctype(const char *);
_END_C_LIB_DECL

 #if defined(__cplusplus) && !defined(_NO_CPP_INLINES)
		/* INLINES, FOR C++ */
_C_LIB_DECL
inline wint_t (towctrans)(wint_t _Wc, wctrans_t _Off)
	{	// translate by category
	return (_Towctrans(_Wc, _Off));
	}
_END_C_LIB_DECL

 #else /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */
	/* DECLARATIONS AND MACRO OVERRIDES, FOR C */
_C_LIB_DECL
wint_t (towctrans)(wint_t, wctrans_t);
_END_C_LIB_DECL
 #endif /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */

_C_STD_END
#endif /* _WCTYPE */

#ifdef _STD_USING
using _CSTD wctrans_t; using _CSTD wctype_t; using _CSTD wint_t;

using _CSTD iswalnum; using _CSTD iswalpha; using _CSTD iswcntrl;
using _CSTD iswctype; using _CSTD iswdigit; using _CSTD iswgraph;
using _CSTD iswlower; using _CSTD iswprint; using _CSTD iswpunct;
using _CSTD iswspace; using _CSTD iswupper; using _CSTD iswxdigit;
using _CSTD towctrans; using _CSTD towlower; using _CSTD towupper;
using _CSTD wctrans; using _CSTD wctype;

 #if _HAS_C9X
using _CSTD iswblank;
 #endif /* _IS_C9X */

#endif /* _STD_USING */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
