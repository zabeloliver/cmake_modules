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

/* stdlib.h standard header */
#ifndef _STDLIB
#define _STDLIB
#include <macro.h>

#ifndef _YVALS
#include <sys/yvals.h>
#endif /* _YVALS */

#include <errno.h>

_C_STD_BEGIN

		/* MACROS */
#ifndef NULL
 #define NULL	_NULL
#endif /* NULL */

#define EXIT_FAILURE	_EXFAIL
#define EXIT_SUCCESS	0

#define MB_CUR_MAX	_CSTD _Getmbcurmax()

 #if _ILONG && !defined(__RX)
  #define RAND_MAX	0x3fffffff

 #else /* _ILONG && !defined(__RX)	*/
  #define RAND_MAX	0x7fff
 #endif /* _ILONG && !defined(__RX)	*/

 #ifndef _NO_RETURN
  #define _NO_RETURN(fun)	void fun
 #endif /* _NO_RETURN */

		/* TYPE DEFINITIONS */

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

typedef struct
	{	/* result of int divide */
	long quot;
	long rem;
	} div_t;

typedef struct
	{	/* result of long divide */
	long quot;
	long rem;
	} ldiv_t;

 #ifndef _LLDIV_T
typedef struct
	{	/* result of long long divide */
	_Longlong quot;
	_Longlong rem;
	} _Lldiv_t;
 #endif /* _LLDIV_T */

 #if _HAS_C9X || defined(__RX)
typedef _Lldiv_t lldiv_t;
 #endif /* _IS_C9X || defined(__RX) */

		/* DECLARATIONS */
_EXTERN_C /* low-level functions */
_NO_RETURN(exit(long));

_NO_RETURN(_Exit(long));	/* added with C99 */
char *getenv(const char *);
long system(const char *);
_END_EXTERN_C

_C_LIB_DECL
#ifdef __cplusplus
int (abs)(int);
#else /* __cplusplus	*/
long (abs)(long);
#endif /* __cplusplus	*/
#ifdef __RX
#ifdef __INTRINSIC_LIB
#ifndef _COMPLEX_
#define abs(i)         _builtin_abs(i)
#ifdef __cplusplus
int _builtin_abs(int);
#else /* __cplusplus	*/
long _builtin_abs(long);
#endif /* __cplusplus	*/
#endif /* !_COMPLEX_	*/
#endif	/* __INTRINSIC_LIB */
#endif	/* __RX */
long labs(long);
_NO_RETURN(abort(void));
void *calloc(size_t, size_t);
div_t div(long, long);
void free(void *);
ldiv_t ldiv(long, long);
void *malloc(size_t);
long mblen(const char *, size_t);
size_t mbstowcs(wchar_t *_Restrict,
	const char *_Restrict, size_t);
long mbtowc(wchar_t *_Restrict, const char *_Restrict, size_t);
long rand(void);
void srand(unsigned long);
void *realloc(void *, size_t);
long strtol(const char *_Restrict, char **_Restrict, long);
size_t wcstombs(char *_Restrict,
	const wchar_t *_Restrict, size_t);
long wctomb(char *, wchar_t);

 #if _ADDED_C_LIB
void lcong48(unsigned short [7]);
unsigned short *seed48(unsigned short [3]);
void srand48(long);

double drand48(void);
long lrand48(void);
long mrand48(void);

double erand48(unsigned short [3]);
long nrand48(unsigned short [3]);
long jrand48(unsigned short [3]);

int getopt(int, char *const *, const char *);
char *mktemp(char *);
int putenv(char *);
int rand_r(unsigned *);
char *tempnam(const char *, const char *);

extern char *optarg;
extern int optind, opterr, optopt;
 #endif /* _ADDED_C_LIB */

unsigned long _Stoul(const char *, char **, long);
float _Stof(const char *, char **, long);
double _Stod(const char *, char **, long);
long double _Stold(const char *, char **, long);
_Longlong _Stoll(const char *, char **, long);
_ULonglong _Stoull(const char *, char **, long);

float _Stofx(const char *, char **, long, long *);
double _Stodx(const char *, char **, long, long *);
long double _Stoldx(const char *, char **, long, long *);
long _Stolx(const char *, char **, long, long *);
unsigned long _Stoulx(const char *, char **, long, long *);
_Longlong _Stollx(const char *, char **, long, long *);
_ULonglong _Stoullx(const char *, char **, long, long *);

size_t _Getmbcurmax(void);

 #if _HAS_C9X || defined(__RX)
_Longlong llabs(_Longlong);
lldiv_t lldiv(_Longlong, _Longlong);
 #endif /* _IS_C9X || defined(__RX) */

_END_C_LIB_DECL

 #if defined(__cplusplus) && !defined(_NO_CPP_INLINES)
_EXTERN_C
typedef void _Atexfun(void);
typedef int _Cmpfun(const void *, const void *);

int atexit(void (*)(void));
void *bsearch(const void *, const void *,
	size_t, size_t, _Cmpfun *);
void qsort(void *, size_t, size_t, _Cmpfun *);
_END_EXTERN_C

#ifdef __RX
_C_LIB_DECL
double atof(const char *);
int atoi(const char *);
long atol(const char *);
double strtod(const char *_Restrict, char **_Restrict);
unsigned long strtoul(const char *_Restrict,
	char **_Restrict, int);
_Longlong atoll(const char *);
_Longlong strtoll(const char *_Restrict,
	char **_Restrict, int);
_ULonglong strtoull(const char *_Restrict,
	char **_Restrict, int);
_END_C_LIB_DECL
#endif /* __RX */

  #if _HAS_STRICT_LINKAGE
typedef int _Cmpfun2(const void *, const void *);

inline int atexit(void (*_Pfn)(void))
	{	// register a function to call at exit
	return (atexit((_Atexfun *)_Pfn));
	}

inline void *bsearch(const void *_Key, const void *_Base,
	size_t _Nelem, size_t _Size, _Cmpfun2 *_Cmp)
	{	// search by binary chop
	return (bsearch(_Key, _Base, _Nelem, _Size, (_Cmpfun *)_Cmp));
	}

inline void qsort(void *_Base,
	size_t _Nelem, size_t _Size, _Cmpfun2 *_Cmp)
	{	// sort
	qsort(_Base, _Nelem, _Size, (_Cmpfun *)_Cmp);
	}
  #endif /* _HAS_STRICT_LINKAGE */

		// INLINES, FOR C++
_C_LIB_DECL
#ifndef __RX
inline double atof(const char *_Str)
	{	// convert string to double
	return (_Stod(_Str, 0, 0));
	}

inline int atoi(const char *_Str)
	{	// convert string to int
	return ((int)_Stoul(_Str, 0, 10));
	}

inline long atol(const char *_Str)
	{	// convert string to long
	return ((long)_Stoul(_Str, 0, 10));
	}

inline double strtod(const char *_Restrict _Str,
	char **_Restrict _Endptr)
	{	// convert string to double, with checking
	return (_Stod(_Str, _Endptr, 0));
	}

inline unsigned long strtoul(const char *_Restrict _Str,
	char **_Restrict _Endptr, int _Base)
	{	// convert string to unsigned long, with checking
	return (_Stoul(_Str, _Endptr, _Base));
	}

 #if _HAS_C9X
inline _Longlong atoll(const char *_Str)
	{	// convert string to long long
	return ((_Longlong)_Stoull(_Str, 0, 10));
	}

inline _Longlong strtoll(const char *_Restrict _Str,
	char **_Restrict _Endptr, int _Base)
	{	// convert string to long long, with checking
	return (_Stoll(_Str, _Endptr, _Base));
	}

inline _ULonglong strtoull(const char *_Restrict _Str,
	char **_Restrict _Endptr, int _Base)
	{	// convert string to unsigned long long, with checking
	return (_Stoull(_Str, _Endptr, _Base));
	}
 #endif /* _IS_C9X */
#endif /* !__RX */

 #if _HAS_C9X
inline float strtof(const char *_Restrict _Str,
	char **_Restrict _Endptr)
	{	// convert string to float, with checking
	return (_Stof(_Str, _Endptr, 0));
	}

inline long double strtold(const char *_Restrict _Str,
	char **_Restrict _Endptr)
	{	// convert string to long double, with checking
	return (_Stold(_Str, _Endptr, 0));
	}
 #endif /* _IS_C9X */

_END_C_LIB_DECL

		// OVERLOADS, FOR C++

  #if !defined(_LLDIV_T) || defined(_LONGLONG)
#ifndef __RX
inline long abs(long _Left)
	{	// compute abs
	return (labs(_Left));
	}

inline ldiv_t div(long _Left, long _Right)
	{	// compute quotient and remainder
	return (ldiv(_Left, _Right));
	}
#endif /* !__RX */
  #endif /* !defined(_LLDIV_T) || defined(_LONGLONG) */

 #if _HAS_C9X || defined(__RX)

  #if !defined(_LLDIV_T) && defined(_LONGLONG)
inline _Longlong abs(_Longlong _Left)
	{	// compute abs
	return (llabs(_Left));
	}

inline _Lldiv_t div(_Longlong _Left, _Longlong _Right)
	{	// compute quotient and remainder
	return (lldiv(_Left, _Right));
	}
  #endif /* !defined(_LLDIV_T) && defined(_LONGLONG) */

 #endif /* _IS_C9X || defined(__RX) */

 #else /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */
_C_LIB_DECL
		/* DECLARATIONS AND MACRO OVERRIDES, FOR C */
typedef long _Cmpfun(const void *, const void *);

/* */ long atexit(void (*)(void));
void *bsearch(const void *, const void *,
	size_t, size_t, _Cmpfun *);
void qsort(void *, size_t, size_t, _Cmpfun *);

double atof(const char *);
long atoi(const char *);
long atol(const char *);
double strtod(const char *_Restrict, char **_Restrict);
unsigned long strtoul(const char *_Restrict,
	char **_Restrict, long);

#ifndef __RX
#define atof(str)	_Stod(str, 0, 0)
#define atoi(str)	(int)_Stoul(str, 0, 10)
#define atol(str)	(long)_Stoul(str, 0, 10)
#define strtod(str, endptr)	_Stod(str, endptr, 0)
#define strtoul(str, endptr, base)	_Stoul(str, endptr, base)
#endif /* !__RX */

 #if _HAS_C9X || defined(__RX)
_Longlong atoll(const char *);
_Longlong strtoll(const char *_Restrict,
	char **_Restrict, long);
_ULonglong strtoull(const char *_Restrict,
	char **_Restrict, long);

#ifndef __RX
#define atoll(str)	(_Longlong)_Stoull(str, 0, 10)
#define strtoll(str, endptr, base)	_Stoll(str, endptr, base)
#define strtoull(str, endptr, base)	_Stoull(str, endptr, base)
#endif /* !__RX */
 #endif /* _IS_C9X || defined(__RX) */

 #if _HAS_C9X
float strtof(const char *_Restrict,
	char **_Restrict);
long double strtold(const char *_Restrict,
	char **_Restrict);

#define strtof(str, endptr)	_Stof(str, endptr, 0)
#define strtold(str, endptr)	_Stold(str, endptr, 0)
 #endif /* _IS_C9X */

_END_C_LIB_DECL
 #endif /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */

 #ifndef _LLDIV_T
  #define _LLDIV_T
 #endif /* _LLDIV_T */

#ifndef __RX
 #define _EXT1_FAIL(mesg)	_Fail_s(mesg, sizeof (mesg))
#endif /* !__RX */

long (_Fail_s)(const char *, size_t);

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

typedef void (*constraint_handler_t)(const char *_Restrict,
	void *_Restrict, errno_t);

constraint_handler_t set_constraint_handler_s(
	constraint_handler_t);
void abort_handler_s(const char *_Restrict,
	void *_Restrict, errno_t);
void ignore_handler_s(const char *_Restrict,
	void *_Restrict, errno_t);

errno_t getenv_s(size_t *_Restrict, char *_Restrict,
	rsize_t, const char *_Restrict);
_END_C_LIB_DECL

  #if defined(__cplusplus) && !defined(_NO_CPP_INLINES)
_EXTERN_C
typedef int _Cmpfun_s(const void *, const void *, void *);

void *bsearch_s(const void *, const void *,
	rsize_t, rsize_t, _Cmpfun_s *, void *);
errno_t qsort_s(void *,
	rsize_t, rsize_t, _Cmpfun_s *, void *);
_END_EXTERN_C

   #if _HAS_STRICT_LINKAGE
typedef int _Cmpfun2_s(const void *, const void *, void *);

inline void *bsearch_s(const void *_Key, const void *_Base,
	rsize_t _Nelem, rsize_t _Size, _Cmpfun2_s *_Cmp, void *_Context)
	{	// search by binary chop
	return (bsearch_s(_Key, _Base, _Nelem, _Size, (_Cmpfun_s *)_Cmp,
		_Context));
	}

inline errno_t qsort_s(void *_Base,
	size_t _Nelem, rsize_t _Size, _Cmpfun2_s *_Cmp, void *_Context)
	{	// sort
	return (qsort_s(_Base, _Nelem, _Size, (_Cmpfun_s *)_Cmp, _Context));
	}
   #endif /* _HAS_STRICT_LINKAGE */

  #else /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */
_C_LIB_DECL
typedef int _Cmpfun_s(const void *, const void *, void *);

void *bsearch_s(const void *, const void *,
	rsize_t, rsize_t, _Cmpfun_s *, void *);
errno_t qsort_s(void *,
	rsize_t, rsize_t, _Cmpfun_s *, void *);
_END_C_LIB_DECL
  #endif /* defined(__cplusplus) && !defined(_NO_CPP_INLINES) */

_C_LIB_DECL
errno_t wctomb_s(int *_Restrict,
	char *_Restrict, rsize_t,
	wchar_t);
errno_t mbstowcs_s(size_t *_Restrict,
	wchar_t *_Restrict, rsize_t,
	const char *_Restrict, rsize_t);
errno_t wcstombs_s(size_t *_Restrict,
	char *_Restrict, rsize_t,
	const wchar_t *_Restrict, rsize_t);
_END_C_LIB_DECL
 #endif /* __STDC_WANT_LIB_EXT1__ */

#ifndef _EXT1_FAIL
 #define _EXT1_FAIL(mesg)	(-1)
#endif /* _EXT1_FAIL */

_C_STD_END
#endif /* _STDLIB */

 #if defined(_STD_USING)

  #ifdef _STD_USING_SIZE_T
using _CSTD size_t;
  #endif /* _STD_USING_SIZE_T */

using _CSTD div_t; using _CSTD ldiv_t;

using _CSTD abort; using _CSTD abs; using _CSTD atexit;
using _CSTD atof; using _CSTD atoi; using _CSTD atol;
using _CSTD bsearch; using _CSTD calloc; using _CSTD div;
using _CSTD exit; using _CSTD free; using _CSTD getenv;
using _CSTD labs; using _CSTD ldiv; using _CSTD malloc;
using _CSTD mblen; using _CSTD mbstowcs; using _CSTD mbtowc;
using _CSTD qsort; using _CSTD rand; using _CSTD realloc;
using _CSTD srand; using _CSTD strtod; using _CSTD strtol;
using _CSTD strtoul; using _CSTD system;
using _CSTD wcstombs; using _CSTD wctomb;

 #if _HAS_C9X || defined(__RX)
using _CSTD lldiv_t;

using _CSTD atoll; using _CSTD llabs; using _CSTD lldiv;
using _CSTD strtoll; using _CSTD strtoull;
 #endif /* _IS_C9X || defined(__RX) */

 #if _HAS_C9X
using _CSTD strtof; using _CSTD strtold;
using _CSTD _Exit;
 #endif /* _IS_C9X */

 #if __STDC_WANT_LIB_EXT1__
using _CSTD errno_t;
using _CSTD rsize_t;
using _CSTD constraint_handler_t;

using _CSTD set_constraint_handler_s;
using _CSTD abort_handler_s;
using _CSTD ignore_handler_s;
using _CSTD getenv_s;
using _CSTD bsearch_s;
using _CSTD qsort_s;
using _CSTD wctomb_s;
using _CSTD mbstowcs_s;
using _CSTD wcstombs_s;
 #endif /* __STDC_WANT_LIB_EXT1__ */

 #endif /* defined(_STD_USING) */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
