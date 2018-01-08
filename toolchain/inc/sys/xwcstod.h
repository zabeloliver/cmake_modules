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
/* xwcstod.h internal header */
#ifndef _WCSTOD
#define _WCSTOD
#include <macro.h>

#if defined(__cplusplus) && !defined(_NO_CPP_INLINES)
		/* INLINES, FOR C++ */
_C_LIB_DECL
inline double wcstod(const wchar_t *_Restrict _Str,
	wchar_t **_Restrict _Endptr)
	{return (_WStod(_Str, _Endptr, 0));
	}

inline unsigned long wcstoul(const wchar_t *_Restrict _Str,
	wchar_t **_Restrict _Endptr, int _Base)
	{return (_WStoul(_Str, _Endptr, _Base));
	}
_END_C_LIB_DECL

  #else /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */
		/* MACROS AND DECLARATIONS, FOR C */

    #if defined(__H8__) || defined(__RX)
	  _C_LIB_DECL
	  double wcstod(const wchar_t *_Restrict _Str, wchar_t **_Restrict _Endptr);
	  unsigned long wcstoul(const wchar_t *_Restrict _Str, wchar_t **_Restrict _Endptr, long _Base);
	  _END_C_LIB_DECL
    #else /* defined(__H8__) || defined(__RX) */
      _C_LIB_DECL
      double wcstod(const wchar_t *, wchar_t **);
      unsigned long wcstoul(const wchar_t *, wchar_t **, int);
      _END_C_LIB_DECL

      #define wcstod(str, endptr)	_WStod(str, endptr, 0)
      #define wcstoul(str, endptr, base)	_WStoul(str, endptr, base)
    #endif /* defined(__H8__) || defined(__RX) */
  #endif /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */
#endif /* _WCSTOD */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */

