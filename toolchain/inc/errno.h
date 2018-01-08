/*
 * Copyright(C) 2007, 2014 Renesas Electronics Corporation
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

/* errno.h standard header */
#ifndef _ERRNO
#define _ERRNO
#include <macro.h>
#ifndef _YVALS
#include <sys/yvals.h>
#endif /* _YVALS */

_C_STD_BEGIN

		/* ERROR CODES */
#define EDOM           0x0021
#define EFAULT         0x000E
#define EFBIG          0x001B
#define EFPOS          0x0098
#define EMLINK         0x001F
#define ENFILE         0x0017
#define ENOENT         0x0002
#define ENOSPC         0x001C
#define ENOTTY         0x0019
#define EPIPE          0x0020
#define ERANGE         0x0022
#define EROFS          0x001E
#define ESPIPE         0x001D

  #define E2BIG         0x0007
  #define EACCES        0x000D
  #define EAGAIN        0x000B
  #define EBADF         0x0009
  #define EBUSY         0x0010
  #define ECHILD        0x000A
  #define EEXIST        0x0011
  #define EINTR         0x0004
  #define EINVAL        0x0016
  #define EIO           0x0005
  #define EISDIR        0x0015
  #define EMFILE        0x0018
  #define ENODEV        0x0013
  #define ENOEXEC       0x0008
  #define ENOMEM        0x000C
  #define ENOTDIR       0x0014
  #define ENXIO         0x0006
  #define EPERM         0x0001
  #define ESRCH         0x0003
  #define EXDEV         0x0012

 #if defined(_MSL_WCHAR_T_TYPE)
  #define EBADMSG       0x004A
  #define ECANCELED     0x007D
  #define EDEADLK       0x0023
  #define EILSEQ        0x0058
  #define EINPROGRESS   0x0073
  #define EMSGSIZE      0x005A
  #define ENAMETOOLONG  0x0024
  #define ENOLCK        0x004D
  #define ENOSYS        0x0026
  #define ENOTEMPTY     0x0027
  #define ENOTSUP       0x005F
  #define ETIMEDOUT     0x006E

 #elif defined(_LINUX_C_LIB)
  #define EBADMSG       0x004A
  #define ECANCELED     0x007D
  #define EDEADLK       0x0023
  #define EILSEQ        0x0054
  #define EINPROGRESS   0x0073
  #define EMSGSIZE      0x005A
  #define ENAMETOOLONG  0x0024
  #define ENOLCK        0x0025
  #define ENOSYS        0x0026
  #define ENOTEMPTY     0x0027
  #define ENOTSUP       0x005F
  #define ETIMEDOUT     0x006E

  #define EWOULDBLOCK	EAGAIN
  #define EAFNOSUPPORT	0x0061

 #else /* library type */
  #define EBADMSG       0x004D
  #define ECANCELED     0x002F
  #define EDEADLK       0x002D
  #define EILSEQ        0x0058
  #define EINPROGRESS   0x0096
  #define EMSGSIZE      0x0061
  #define ENAMETOOLONG  0x004E
  #define ENOLCK        0x002E
  #define ENOSYS        0x0059
  #define ENOTEMPTY     0x005D
  #define ENOTSUP       0x0030
  #define ETIMEDOUT     0x0091
 #endif /* library type */

#ifdef __RX
	#define ESTRN   0x0450		/* 1104 */
	#define ECBASE  0x04B0		/* 1200 */
	#define ETLN    0x04B2		/* 1202 */
	#define EEXP    0x04B4		/* 1204 */
	#define EEXPN   0x04B6		/* 1206 */
	#define EFLOATO 0x04BA		/* 1210 */
	#define EFLOATU 0x04C4		/* 1220 */
	#define EDBLO   0x04E2		/* 1250 */
	#define EDBLU   0x04EC		/* 1260 */
	#define ELDBLO  0x04F6		/* 1270 */
	#define ELDBLU  0x0500		/* 1280 */
#endif /* __RX */

#define	EMALRESM	2100
#define	ETOKRESM 	2110
#define	EFLSRESM	2120
#define	EMBLNRESM	2130
#define	EFPSWRESM	2140
#define	EMALFRSM	2101
#define	ETOKFRSM	2111
#define	EFLSFRSM	2121
#define	EMBLNFRSM	2131
#define	EFPSWFRSM	2141

		/* DECLARATIONS */
_C_LIB_DECL


#ifdef __RX

	#ifndef _R_REENT
		extern volatile long _errno;
	#else
		#define _errno (*errno_addr())
		long  *errno_addr(void);
	#endif

	#ifndef  errno
		#define  errno          _errno
	#endif

#else /* __RX */

 #if !_MULTI_THREAD || _COMPILER_TLS && !_GLOBAL_LOCALE
extern int _TLS_QUAL _Errno;

  #define errno	(_CSTD _Errno)

 #else /* !_MULTI_THREAD || _COMPILER_TLS && !_GLOBAL_LOCALE */
int *_Geterrno(void);

  #define errno	(*_CSTD _Geterrno())
 #endif /* !_MULTI_THREAD || _COMPILER_TLS && !_GLOBAL_LOCALE */

#endif /* __RX */

_END_C_LIB_DECL

 #if __STDC_WANT_LIB_EXT1__
_C_LIB_DECL

  #if !defined(_ERRNO_T_DEFINED)
   #define _ERRNO_T_DEFINED
typedef int errno_t;
  #endif /* _ERRNO_T_DEFINED */

_END_C_LIB_DECL
 #endif /* __STDC_WANT_LIB_EXT1__ */

_C_STD_END
#endif /* _ERRNO */

 #if defined(_STD_USING)

 #if __STDC_WANT_LIB_EXT1__
using _CSTD errno_t;
 #endif /* __STDC_WANT_LIB_EXT1__ */

 #endif /* defined(_STD_USING) */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
