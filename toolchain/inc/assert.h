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

/* assert.h standard header */
#include <macro.h>
#ifndef _YVALS
#include <sys/yvals.h>
#endif /* _YVALS */
#include <stdio.h>
#include <stdlib.h>

_C_STD_BEGIN

#undef assert	/* remove existing definition */

#ifdef NDEBUG
 #define assert(test)	((void)0)

#else /* NDEBUG */
  #define _STRIZE(x)	_VAL(x)
  #define _VAL(x)	#x

 #ifdef _WIN32_WCE
  #define _WIDEN(x) _SYSCH(x)

   #define assert(test)	((test) ? (void)0 \
	: _CSTD _Assert(_WIDEN(__FILE__) _WIDEN(":") _WIDEN(_STRIZE(__LINE__)) \
		_WIDEN(" ") _WIDEN(_STRIZE(test))))

_C_LIB_DECL
void _Assert(const _Sysch_t *);
_END_C_LIB_DECL

 #else /* _WIN32_WCE */

 #if 199901L <= __STDC_VERSION__

  #ifdef __cplusplus
   #define _FUNNAME	0

  #else /* __cplusplus */
   #define _FUNNAME	__func__
  #endif /* __cplusplus */

 #else /* 199901L <= __STDC_VERSION__ */
  #define _FUNNAME	0
 #endif /* 199901L <= __STDC_VERSION__ */

 #ifdef __RX
	#if defined(_C99) && !defined(__cplusplus)
		#define assert(test)	((test) ? (void)0: \
			(fprintf(stderr,"ASSERTION FAILED: "#test" FILE %s,LINE %d FUNCNAME %s \n", \
			__FILE__,__LINE__,_FUNNAME),abort(),(void)0))
	#else
		#define assert(test)	((test) ? (void)0: \
			(fprintf(stderr,"ASSERTION FAILED: "#test" FILE %s,LINE %d \n", \
			__FILE__,__LINE__,_FUNNAME),abort(),(void)0))
	#endif
 #else	/* __RX */

  #ifdef _VERBOSE_DEBUGGING
   #include <stdio.h>

   #define assert(test)	((test) ? (void)_CSTD fprintf(stderr, \
	__FILE__ ":" _STRIZE(__LINE__) " " #test " -- OK\n") \
	: _CSTD _Assert(__FILE__ ":" _STRIZE(__LINE__) " " #test, \
		_FUNNAME))

  #else /* _VERBOSE_DEBUGGING */
   #define assert(test)	((test) ? (void)0 \
	: _CSTD _Assert(__FILE__ ":" _STRIZE(__LINE__) " " #test, _FUNNAME))
  #endif /* _VERBOSE_DEBUGGING */

_C_LIB_DECL
void _Assert(const char *, const char *);
_END_C_LIB_DECL

 #endif /* __RX */

 #endif /* _WIN32_WCE */

 #endif /* NDEBUG */
_C_STD_END

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
