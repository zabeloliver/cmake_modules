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

/* string.h standard header */
#ifndef _STRING
#define _STRING
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

		/* type definitions */

 #if !defined(_SIZE_T) && !defined(_SIZET) && !defined(_SIZE_T_DEFINED) \
	&& !defined(_BSD_SIZE_T_DEFINED_)
  #define _SIZE_T
  #define _SIZET
  #define _BSD_SIZE_T_DEFINED_
  #define _SIZE_T_DEFINED
  #define _STD_USING_SIZE_T
typedef _Sizet size_t;
 #endif /* !defined(_SIZE_T) etc. */

		/* declarations */
_C_LIB_DECL
long memcmp(const void *, const void *, size_t);
char *(strcat)(char *_Restrict, const char *_Restrict);
void *(memcpy)(void *_Restrict, const void *_Restrict, size_t);
void *(memset)(void *, long, size_t);
long (strcmp)(const char *, const char *);
char *(strcpy)(char *_Restrict, const char *_Restrict);
size_t (strlen)(const char *);
void *(memmove)(void *, const void *, size_t);
long strcoll(const char *, const char *);
size_t strcspn(const char *, const char *);
char *strerror(long);
char *(strncat)(char *_Restrict, const char *_Restrict, size_t);
long (strncmp)(const char *, const char *, size_t);
char *(strncpy)(char *_Restrict, const char *_Restrict, size_t);
size_t strspn(const char *, const char *);
char *strtok(char *_Restrict, const char *_Restrict);
size_t strxfrm(char *_Restrict, const char *_Restrict, size_t);

#ifdef __RX
#ifdef __INTRINSIC_LIB
#define memcpy(s1,s2,s3)  _builtin_memcpy(s1,s2,s3)
#define memset(s1,s2,s3)  _builtin_memset(s1,s2,s3)
#define memmove(s1,s2,s3)	_builtin_memmove(s1,s2,s3)
#define strlen(s1)			_builtin_strlen(s1)
#define strcat(s1,s2)		_builtin_strcat(s1,s2)
#define strncat(s1,s2,s3)	_builtin_strncat(s1,s2,s3)
#define strcmp(s1,s2)     _builtin_strcmp(s1,s2)
#define strcpy(s1,s2)     _builtin_strcpy(s1,s2)
#define strncmp(s1,s2,s3) _builtin_strncmp(s1,s2,s3)
#define strncpy(s1,s2,s3) _builtin_strncpy(s1,s2,s3)
void *_builtin_memcpy(void *_Restrict, const void *_Restrict, size_t);
void *_builtin_memset(void *, long, size_t);
void *_builtin_memmove(void *, const void *, size_t);
size_t _builtin_strlen(const char *);
char *_builtin_strcat(char *_Restrict, const char *_Restrict);
char *_builtin_strncat(char *_Restrict, const char *_Restrict, size_t);
long _builtin_strcmp(const char *, const char *);
char *_builtin_strcpy(char *_Restrict, const char *_Restrict);
long _builtin_strncmp(const char *, const char *, size_t);
char *_builtin_strncpy(char *_Restrict, const char *_Restrict, size_t);
#endif	/* __INTRINSIC_LIB */
#endif	/* __RX */

 #if _ADDED_C_LIB
char *strdup(const char *);
int strcasecmp(const char *, const char *);
int strncasecmp(const char *, const char *, size_t);
char *strtok_r(char *, const char *, char **);
 #endif /* _ADDED_C_LIB */

_END_C_LIB_DECL

 #if defined(__cplusplus) && !defined(_NO_CPP_INLINES)
		// INLINES AND OVERLOADS, for C++
 #define _Const_return const

_C_LIB_DECL
const char *strchr(const char *, int);
const char *strpbrk(const char *, const char *);
const char *strrchr(const char *, int);
const char *strstr(const char *, const char *);
_END_C_LIB_DECL

inline char *strchr(char *_Str, int _Ch)
	{	// call with const first argument
	return ((char *)_CSTD strchr((const char *)_Str, _Ch));
	}

inline char *strpbrk(char *_Str1, const char *_Str2)
	{	// call with const first argument
	return ((char *)_CSTD strpbrk((const char *)_Str1, _Str2));
	}

inline char *strrchr(char *_Str, int _Ch)
	{	// call with const first argument
	return ((char *)_CSTD strrchr((const char *)_Str, _Ch));
	}

inline char *strstr(char *_Str1, const char *_Str2)
	{	// call with const first argument
	return ((char *)_CSTD strstr((const char *)_Str1, _Str2));
	}

 #else /* defined(__cplusplus) && !defined(_NO_CPP_INLINES)*/
_C_LIB_DECL
 #define _Const_return

char *strchr(const char *, long);
char *strpbrk(const char *, const char *);
char *strrchr(const char *, long);
char *strstr(const char *, const char *);
_END_C_LIB_DECL
 #endif /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */

 #ifndef _MEMCHR
  #define _MEMCHR

  #if defined(__cplusplus) && !defined(_NO_CPP_INLINES)
_C_LIB_DECL
const void *(memchr)(const void *, int, size_t);
#ifdef __RX
#ifdef __INTRINSIC_LIB
#define memchr(s1,s2,s3)  _builtin_memchr(s1,s2,s3)
const void *_builtin_memchr(const void *, int, size_t);
#endif	/* __INTRINSIC_LIB */
#endif	/* __RX */
_END_C_LIB_DECL

inline void *memchr(void *_Str, int _Ch, size_t _Num)
	{	// call with const first argument
	return ((void *)_CSTD memchr((const void *)_Str, _Ch, _Num));
	}

  #else /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */
_C_LIB_DECL
void *(memchr)(const void *, long, size_t);
#ifdef __RX
#ifdef __INTRINSIC_LIB
#define memchr(s1,s2,s3)  _builtin_memchr(s1,s2,s3)
void *_builtin_memchr(const void *, long, size_t);
#endif	/* __INTRINSIC_LIB */
#endif	/* __RX */
_END_C_LIB_DECL
  #endif /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */

 #endif /* _MEMCHR */

 #if __STDC_WANT_LIB_EXT1__
_C_LIB_DECL

  #if !defined(_ERRNO_T_DEFINED)
   #define _ERRNO_T_DEFINED
typedef int errno_t;
  #endif /* _ERRNO_T_DEFINED */

  #if !defined(_RSIZE_T_DEFINED)
   #define _RSIZE_T_DEFINED
typedef size_t rsize_t;
  #endif /* _RSIZE_T_DEFINED */

errno_t memcpy_s(void *_Restrict, rsize_t,
	const void *_Restrict, rsize_t);
errno_t memmove_s(void *, rsize_t,
	const void *, rsize_t);

errno_t strcpy_s(char *_Restrict, rsize_t,
	const char *_Restrict);
errno_t strncpy_s(char *_Restrict, rsize_t,
	const char *_Restrict, rsize_t);
errno_t strcat_s(char *_Restrict, rsize_t,
	const char *_Restrict);
errno_t strncat_s(char *_Restrict, rsize_t,
	const char *_Restrict, rsize_t);
char *strtok_s(char *_Restrict, rsize_t *_Restrict,
	const char *_Restrict, char **_Restrict);

errno_t strerror_s(char *, rsize_t, errno_t);
size_t strerrorlen_s(errno_t);

size_t strnlen_s(const char *_Restrict, size_t);
_END_C_LIB_DECL
 #endif /* __STDC_WANT_LIB_EXT1__ */

_C_STD_END
#endif /* _STRING */

 #if defined(_STD_USING)

  #ifdef _STD_USING_SIZE_T
using _CSTD size_t;
  #endif /* _STD_USING_SIZE_T */

using _CSTD memchr; using _CSTD memcmp;
using _CSTD memcpy; using _CSTD memmove; using _CSTD memset;
using _CSTD strcat; using _CSTD strchr; using _CSTD strcmp;
using _CSTD strcoll; using _CSTD strcpy; using _CSTD strcspn;
using _CSTD strerror; using _CSTD strlen; using _CSTD strncat;
using _CSTD strncmp; using _CSTD strncpy; using _CSTD strpbrk;
using _CSTD strrchr; using _CSTD strspn; using _CSTD strstr;
using _CSTD strtok; using _CSTD strxfrm;

 #if __STDC_WANT_LIB_EXT1__
using _CSTD errno_t;
using _CSTD rsize_t;

using _CSTD memcpy_s;
using _CSTD memmove_s;
using _CSTD strcpy_s;
using _CSTD strncpy_s;
using _CSTD strcat_s;
using _CSTD strncat_s;
using _CSTD strtok_s;
using _CSTD strerror_s;
using _CSTD strerrorlen_s;
using _CSTD strnlen_s;
 #endif /* __STDC_WANT_LIB_EXT1__ */

 #endif /* defined(_STD_USING) */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
