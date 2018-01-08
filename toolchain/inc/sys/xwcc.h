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
/* xwcc.h internal header */
#ifndef _XWCC
#define _XWCC
#include <macro.h>

_C_LIB_DECL
long _Iswctype(wint_t, wctype_t);
wint_t _Towctrans(wint_t, wctrans_t);
_END_C_LIB_DECL

  #if defined(__cplusplus) && !defined(_NO_CPP_INLINES)
		// INLINES, FOR C++
_C_LIB_DECL
inline int iswalnum(wint_t _Wc)
	{	// test for alnum
	return (_Iswctype(_Wc, 1));
	}

inline int iswalpha(wint_t _Wc)
	{	// test for alpha
	return (_Iswctype(_Wc, 2));
	}

inline int iswcntrl(wint_t _Wc)
	{	// test for cntrl
	return (_Iswctype(_Wc, 3));
	}

inline int iswctype(wint_t _Wc, wctype_t _Off)
	{	// test for ctype category
	return (_Iswctype(_Wc, _Off));
	}

inline int iswdigit(wint_t _Wc)
	{	// test for digit
	return (_Iswctype(_Wc, 4));
	}

inline int iswgraph(wint_t _Wc)
	{	// test for graph
	return (_Iswctype(_Wc, 5));
	}

inline int iswlower(wint_t _Wc)
	{	// test for lower
	return (_Iswctype(_Wc, 6));
	}

inline int iswprint(wint_t _Wc)
	{	// test for print
	return (_Iswctype(_Wc, 7));
	}

inline int iswpunct(wint_t _Wc)
	{	// test for punct
	return (_Iswctype(_Wc, 8));
	}

inline int iswspace(wint_t _Wc)
	{	// test for space
	return (_Iswctype(_Wc, 9));
	}

inline int iswupper(wint_t _Wc)
	{	// test for upper
	return (_Iswctype(_Wc, 10));
	}

inline int iswxdigit(wint_t _Wc)
	{	// test for xdigit
	return (_Iswctype(_Wc, 11));
	}

inline wint_t towlower(wint_t _Wc)
	{	// translate to lower
	return (_Towctrans(_Wc, 1));
	}

inline wint_t towupper(wint_t _Wc)
	{	// translate to upper
	return (_Towctrans(_Wc, 2));
	}

 #if _HAS_C9X
inline int iswblank(wint_t _Wc)
	{	// check blank bits
	return (_Iswctype(_Wc, 12));
	}
 #endif /* _IS_C9X */

_END_C_LIB_DECL

  #else /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */
	/* DECLARATIONS AND MACRO OVERRIDES, FOR C */
_C_LIB_DECL
long iswalnum(wint_t);
long iswalpha(wint_t);
long iswcntrl(wint_t);
long iswctype(wint_t, wctype_t);
long iswdigit(wint_t);
long iswgraph(wint_t);
long iswlower(wint_t);
long iswprint(wint_t);
long iswpunct(wint_t);
long iswspace(wint_t);
long iswupper(wint_t);
long iswxdigit(wint_t);

wint_t towlower(wint_t);
wint_t towupper(wint_t);

 #if _HAS_C9X
long iswblank(wint_t);
 #endif /* _IS_C9X */

_END_C_LIB_DECL

#ifndef _DNK_RENAME
 #define iswalnum(wc)	_Iswctype(wc, 1)
 #define iswalpha(wc)	_Iswctype(wc, 2)
 #define iswcntrl(wc)	_Iswctype(wc, 3)
 #define iswctype(wc, off)	_Iswctype(wc, off)
 #define iswdigit(wc)	_Iswctype(wc, 4)
 #define iswgraph(wc)	_Iswctype(wc, 5)
 #define iswlower(wc)	_Iswctype(wc, 6)
 #define iswprint(wc)	_Iswctype(wc, 7)
 #define iswpunct(wc)	_Iswctype(wc, 8)
 #define iswspace(wc)	_Iswctype(wc, 9)
 #define iswupper(wc)	_Iswctype(wc, 10)
 #define iswxdigit(wc)	_Iswctype(wc, 11)
 #define towctrans(wc, off)	_Towctrans(wc, off)
 #define towlower(wc)	_Towctrans(wc, 1)
 #define towupper(wc)	_Towctrans(wc, 2)
#endif /* _DNK_RENAME */

 #if _HAS_C9X
 #define iswblank(wc)	_Iswctype(wc, 12)
 #endif /* _IS_C9X */

  #endif /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */

#endif /* _XWCC */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
