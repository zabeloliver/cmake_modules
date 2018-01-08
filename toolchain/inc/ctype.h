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

/* ctype.h standard header */
#ifndef _CTYPE
#define _CTYPE
#include <macro.h>
#ifndef _YVALS
#include <sys/yvals.h>
#endif /* _YVALS */

_C_STD_BEGIN

		/* _Ctype code bits */
#define _XB		0x400 /* extra blank */
#define _XA		0x200 /* extra alphabetic */
#define _XS		0x100 /* extra space */
#define _BB		0x80 /* BEL, BS, etc. */
#define _CN		0x40 /* CR, FF, HT, NL, VT */
#define _DI		0x20 /* '0'-'9' */
#define _LO		0x10 /* 'a'-'z' */
#define _PU		0x08 /* punctuation */
#define _SP		0x04 /* space */
#define _UP		0x02 /* 'A'-'Z' */
#define _XD		0x01 /* '0'-'9', 'A'-'F', 'a'-'f' */

_C_LIB_DECL
typedef const short *_Ctype_t;

_Ctype_t _Getpctype(void);
_Ctype_t _Getptolower(void);
_Ctype_t _Getptoupper(void);

 #if !_MULTI_THREAD || _COMPILER_TLS && !_GLOBAL_LOCALE
extern _Ctype_t _TLS_QUAL _Ctype;
extern _Ctype_t _TLS_QUAL _Tolotab;
extern _Ctype_t _TLS_QUAL _Touptab;

  #define _Getpctype()		_Ctype
  #define _Getptolower()	_Tolotab
  #define _Getptoupper()	_Touptab
 #endif /* !_MULTI_THREAD || _COMPILER_TLS && !_GLOBAL_LOCALE */

#define _Getchrtype(x)	_Getpctype()[(long)(x)]
#define _CTolower(x)	_Getptolower()[(long)(x)]
#define _CToupper(x)	_Getptoupper()[(long)(x)]
_END_C_LIB_DECL

 #if defined(__cplusplus) && !defined(_NO_CPP_INLINES)
		// INLINES, for C++
_C_LIB_DECL
inline int isalnum(int _Ch)
	{	// check alnum bits
	return (_Getchrtype(_Ch) & (_DI|_LO|_UP|_XA));
	}

inline int isalpha(int _Ch)
	{	// check alpha bits
	return (_Getchrtype(_Ch) & (_LO|_UP|_XA));
	}

inline int iscntrl(int _Ch)
	{	// check cntrl bits
	return (_Getchrtype(_Ch) & _BB);
	}

inline int isdigit(int _Ch)
	{	// check digit bits
	return (_Getchrtype(_Ch) & _DI);
	}

inline int isgraph(int _Ch)
	{	// check graph bits
	return (_Getchrtype(_Ch) & (_DI|_LO|_PU|_UP|_XA));
	}

inline int islower(int _Ch)
	{	// check alnum bits
	return (_Getchrtype(_Ch) & _LO);
	}

inline int isprint(int _Ch)
	{	// check print bits
	return (_Getchrtype(_Ch) & (_DI|_LO|_PU|_SP|_UP|_XA));
	}

inline int ispunct(int _Ch)
	{	// check punct bits
	return (_Getchrtype(_Ch) & _PU);
	}

inline int _Isspace(int _Ch)
	{	// check space bits
	return (_Getchrtype(_Ch) & (_CN|_SP|_XS));
	}

inline int isspace(int _Ch)
	{	// check space bits
	return (_Isspace(_Ch));
	}

inline int isupper(int _Ch)
	{	// check upper bits
	return (_Getchrtype(_Ch) & _UP);
	}

inline int isxdigit(int _Ch)
	{	// check xdigit bits
	return (_Getchrtype(_Ch) & _XD);
	}

 #if _HAS_C9X
inline int isblank(int _Ch)
	{	// check blank bits
	return (_Getchrtype(_Ch) & (_SP|_XB));
	}
 #endif /* _IS_C9X */

inline int tolower(int _Ch)
	{	// convert to lower case
	return (_CTolower(_Ch));
	}

inline int toupper(int _Ch)
	{	// convert to upper case
	return (_CToupper(_Ch));
	}
_END_C_LIB_DECL

 #else /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */
		/* declarations and macro overrides, for C */
_C_LIB_DECL
long isalnum(long);
long isalpha(long);
long iscntrl(long);
long isdigit(long);
long isgraph(long);
long islower(long);
long isprint(long);
long ispunct(long);
long isspace(long);
long isupper(long);
long isxdigit(long);
long tolower(long);
long toupper(long);

 #if _HAS_C9X
long isblank(long);
 #endif /* _IS_C9X */

_END_C_LIB_DECL

  #define isalnum(c)		(_Getchrtype(c) & (_DI|_LO|_UP|_XA))

  #ifdef isalpha
   #define _dnk_isalpha(c)	(_Getchrtype(c) & (_LO|_UP|_XA))

  #else /* _dnk_isalpha */
   #define isalpha(c)		(_Getchrtype(c) & (_LO|_UP|_XA))
  #endif /* _dnk_isalpha */

  #define iscntrl(c)		(_Getchrtype(c) & _BB)
  #define isdigit(c)		(_Getchrtype(c) & _DI)
  #define isgraph(c)		(_Getchrtype(c) & (_DI|_LO|_PU|_UP|_XA))

  #ifdef islower
   #define _dnk_islower(c)	(_Getchrtype(c) & _LO)

  #else /* _dnk_islower */
   #define islower(c)		(_Getchrtype(c) & _LO)
  #endif /* _dnk_islower */

  #define isprint(c)		(_Getchrtype(c) & (_DI|_LO|_PU|_SP|_UP|_XA))
  #define ispunct(c)		(_Getchrtype(c) & _PU)
  #define isspace(c)		(_Getchrtype(c) & (_CN|_SP|_XS))
  #define isupper(c)		(_Getchrtype(c) & _UP)
  #define isxdigit(c	)	(_Getchrtype(c) & _XD)

 #if _HAS_C9X
  #define isblank(c)		(_Getchrtype(c) & (_SP|_XB))
 #endif /* _IS_C9X */

 #ifndef _DNK_RENAME
  #define tolower(c)	_CTolower(c)
  #define toupper(c)	_CToupper(c)
 #endif /* _DNK_RENAME */

 #endif /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */

_C_STD_END
#endif /* _CTYPE */

#ifdef _STD_USING
using _CSTD isalnum; using _CSTD isalpha; using _CSTD iscntrl;
using _CSTD isdigit; using _CSTD isgraph; using _CSTD islower;
using _CSTD isprint; using _CSTD ispunct; using _CSTD isspace;
using _CSTD isupper; using _CSTD isxdigit; using _CSTD tolower;
using _CSTD toupper; using _CSTD _Isspace;

 #if _HAS_C9X
using _CSTD isblank;
 #endif /* _IS_C9X */

#endif /* _STD_USING */


/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
