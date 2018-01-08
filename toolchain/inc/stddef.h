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

/* stddef.h standard header */
#ifndef _STDDEF
#define _STDDEF
#include <macro.h>

#ifndef _YVALS
#include <sys/yvals.h>
#endif /* _YVALS */

#include <errno.h>

_C_STD_BEGIN

		/* macros */
#ifndef NULL
 #define NULL	_NULL
#endif /* NULL */

#ifndef offsetof

 #if __EDG__
  #ifdef __RX
    #ifdef __cplusplus
      #define offsetof(t, memb) ((size_t)(&(((t *)0)->memb)))
    #else
      #define offsetof(type,id) ((char *)(&(((type *)NULL)->id))  -    \
                                 (char *)((type *)NULL))
    #endif
  #else /* __RX */
  #define offsetof(T, member) ((_Sizet)__INTADDR__(&(((T *)0)->member)))
  #endif /* __RX */

 #else /* __EDG__ */
  #define offsetof(T, member)	((_CSTD size_t)&(((T *)0)->member))
 #endif /* __EDG__ */

#endif /* offsetof */

		/* type definitions */

 #if !defined(_PTRDIFF_T) && !defined(_PTRDIFFT) \
	&& !defined(_PTRDIFF_T_DEFINED)
  #define _PTRDIFF_T
  #define _PTRDIFFT
  #define _PTRDIFF_T_DEFINED
  #define _STD_USING_PTRDIFF_T
typedef _Ptrdifft ptrdiff_t;
 #endif /* !defined(_PTRDIFF_T) etc. */

 #if !defined(_SIZE_T) && !defined(_SIZET) && !defined(_SIZE_T_DEFINED) \
	&& !defined(_BSD_SIZE_T_DEFINED_)
  #define _SIZE_T
  #define _SIZET
  #define _BSD_SIZE_T_DEFINED_
  #define _SIZE_T_DEFINED
  #define _STD_USING_SIZE_T
typedef _Sizet size_t;
 #endif /* !defined(_SIZE_T) etc. */

 #if !defined(_WCHART) && !defined(_WCHAR_T_DEFINED)
  #define _WCHART
  #define _WCHAR_T_DEFINED
typedef _Wchart wchar_t;
 #endif /* _WCHART etc. */

 #if __STDC_WANT_LIB_EXT1__

  #if !defined(_RSIZE_T_DEFINED)
   #define _RSIZE_T_DEFINED
typedef size_t rsize_t;
  #endif /* _RSIZE_T_DEFINED */

 #endif /* __STDC_WANT_LIB_EXT1__ */
_C_STD_END
#endif /* _STDDEF */

 #if defined(_STD_USING)

  #ifdef _STD_USING_PTRDIFF_T
using _CSTD ptrdiff_t;
  #endif /* _STD_USING_PTRDIFF_T */

  #ifdef _STD_USING_SIZE_T
using _CSTD size_t;
  #endif /* _STD_USING_SIZE_T */

 #if __STDC_WANT_LIB_EXT1__
using _CSTD rsize_t;
 #endif /* __STDC_WANT_LIB_EXT1__ */

 #endif /* defined(_STD_USING) */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
