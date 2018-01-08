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
/* yvals.h values header for conforming compilers on various systems */
#include <macro.h>

#ifndef _YVALS
#define _YVALS

#define _CPPLIB_VER	503

/* You can predefine (on the compile command line, for example):

_ADDED_C_LIB=0 -- to omit declarations for C extensions
_ALT_NS=1 -- to use namespace _Dinkum_std for C++
_ALT_NS=2 -- to use namespace _Dinkum_std for C++ and C
_ALT_NS=3 -- to use namespace _Dinkum_std for C++ and _Dinkum_std_c for C
_C_AS_CPP -- to compile C library as C++
_C_IN_NS -- to define C names in std/_Dinkum_std instead of global namespace
_C99 -- to turn ON C99 library support
_ABRCPP -- to turn ON Abridged C++ dialect (implies _ECPP)
_ECPP -- to turn ON Embedded C++ dialect
_HAS_FIXED_POINT=0 -- to turn OFF fixed-point extensions (if present)
_HAS_IMMUTABLE_SETS=1 -- to permit alterable set elements
_HAS_STRICT_CONFORMANCE=1 -- to to disable nonconforming extensions
_HAS_TRADITIONAL_IOSTREAMS=0 -- to omit old iostreams functions
_HAS_TRADITIONAL_ITERATORS=1 -- for vector/string pointer iterators
_HAS_TRADITIONAL_POS_TYPE=1 -- for streampos same as streamoff
_HAS_TRADITIONAL_STL=0 -- to turn OFF old STL functions
_HAS_TR1=0 -- to turn OFF TR1 extensions (if present)
_NO_EX -- to turn OFF use of try/throw
_NO_MT -- to turn OFF thread synchronization
_NO_NS -- to turn OFF use of namespace declarations
_STL_DB (or _STLP_DEBUG) -- to turn ON iterator/range debugging
_USE_EXISTING_SYSTEM_NAMES=0 -- to disable mappings (_Open to open)
__NO_LONG_LONG -- to define _Longlong as long, not long long

You can change (in this header AND ALL ITS COPIES):

_COMPILER_TLS -- from 0 to 1 if _TLS_QUAL is not nil
_EXFAIL -- from 1 to any nonzero value for EXIT_FAILURE
_FILE_OP_LOCKS -- from 0 to 1 for file atomic locks
_GLOBAL_LOCALE -- from 0 to 1 for shared locales instead of per-thread
_IOSTREAM_OP_LOCKS -- from 0 to 1 for iostream atomic locks
_TLS_QUAL -- from nil to compiler TLS qualifier, such as __declspec(thread)
__STDC_WANT_LIB_EXT1__ -- from 1 to 0 to disable C library extension 1

Include directories needed to compile with Dinkum C:

C -- include/c
C99 -- include/c (define _C99)
Embedded C++ -- include/c include/embedded (define _ECPP)
Abridged C++ -- include/c include/embedded include (define _ABRCPP)
Standard C++ -- include/c include
Standard C++ with export -- include/c include/export include
	(--export --template_dir=lib/export)

Include directories needed to compile with native C:

C -- none
C99 -- N/A
Embedded C++ -- include/embedded (define _ECPP)
Abridged C++ -- include/embedded include (define _ABRCPP)
Standard C++ -- include
Standard C++ with export -- include/export include
	(--export --template_dir=lib/export)
 */

 #ifndef __STDC_HOSTED__
  #define __STDC_HOSTED__	1
 #endif /* __STDC_HOSTED__ */

 #ifndef __STDC_IEC_559__
  #define __STDC_IEC_559__	1
 #endif /* __STDC_IEC_559__ */

 #ifndef __STDC_IEC_559_COMPLEX__
  #define __STDC_IEC_559_COMPLEX__	1
 #endif /* __STDC_IEC_559_COMPLEX__ */

 #ifndef __STDC_ISO_10646__
  #define __STDC_ISO_10646__	200009L	/* match glibc */
 #endif /* __STDC_ISO_10646__ */

 #ifndef __STDC_LIB_EXT1__
  #define __STDC_LIB_EXT1__	200509L
 #endif /* __STDC_LIB_EXT1__ */

 #ifndef __STDC_WANT_LIB_EXT1__
  #define __STDC_WANT_LIB_EXT1__	1
 #endif /* __STDC_WANT_LIB_EXT1__ */

		/* DETERMINE MACHINE TYPE */

 #if defined(i386) || defined(__i386) \
	|| defined(__i386__) || defined(_M_IX86)	/* Pentium */
  #define _D0		3	/* 0: big endian, 3: little endian floating-point */

  #if defined(_M_IX86)
   #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
   #define _LBIAS	0x3fe	/* 64 long double bits */
   #define _LOFF	4	/* 64 long double bits */

  #else /* unknown compilation environment, guess 80-bit long double */
   #define _DLONG	1	/* 0: 64, 1: 80, 2: 128 long double bits */
   #define _LBIAS	0x3ffe	/* 80/128 long double bits */
   #define _LOFF	15	/* 80/128 long double bits */
  #endif /* defined(_M_IX86) */

  #define _FPP_TYPE	_FPP_X86	/* Pentium FPP */

 #elif defined(sparc) || defined(__sparc)	/* SPARC */

  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	2	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
  #define _LOFF		15	/* 80/128 long double bits */
  #define _FPP_TYPE	_FPP_SPARC	/* SPARC FPP */

 #elif defined(_MIPS) || defined(_MIPS_) \
	|| defined(__mips) || defined(_M_MRX000)		/* MIPS */

  #if defined(__LITTLE_ENDIAN__) || defined(__MIPSEL)
   #define _D0		3	/* 0: big endian, 3: little endian floating-point */

  #else /* __LITTLE_ENDIAN__ etc. */
   #define _D0		0
  #endif /* __LITTLE_ENDIAN__ etc. */

  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3fe	/* 64 long double bits */
  #define _LOFF		4	/* 64 long double bits */
  #define _FPP_TYPE	_FPP_MIPS	/* MIPS FPP */

 #if !defined(_MACH_PDT)
  #define _MACH_PDT	long
  #define _MACH_SZT	unsigned long
 #endif /* defined(_MACH_PDT) */

 #elif defined(__s390__)	/* IBM S/390 */
  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3fe	/* 64 long double bits */
  #define _LOFF		4	/* 64 long double bits */
  #define _FPP_TYPE	_FPP_S390	/* S/390 FPP */

  #define _MACH_PDT	long
  #define _MACH_SZT	unsigned long

 #elif defined(__ppc__) || defined(_POWER) || defined(_M_PPC)	/* PowerPC */
  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3fe	/* 64 long double bits */
  #define _LOFF		4	/* 64 long double bits */
  #define _FPP_TYPE	_FPP_PPC	/* PowerPC FPP */

 #elif defined(__hppa)	/* HP PA-RISC */
  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	2	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
  #define _LOFF		15	/* 80/128 long double bits */
  #define _FPP_TYPE	_FPP_HPPA	/* Hewlett-Packard PA-RISC FPP */

 #elif defined(_M_ALPHA)	/* Alpha */
  #define _D0		3	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3fe	/* 64 long double bits */
  #define _LOFF		4	/* 64 long double bits */
  #define _FPP_TYPE	_FPP_ALPHA	/* Compaq Alpha */

 #elif defined(_ARM_) || defined(__arm)	/* ARM */

  #if defined(__BIG_ENDIAN__) || defined(__ARMEB__)
   #define _D0		0	/* 0: big endian, 3: little endian floating-point */

  #else /* __BIG_ENDIAN__ etc. */
   #define _D0		3	/* 0: big endian, 3: little endian floating-point */
  #endif /* __BIG_ENDIAN__ etc. */

  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3fe	/* 64 long double bits */
  #define _LOFF		4	/* 64 long double bits */
  #define _FPP_TYPE	_FPP_ARM	/* ARM ARM FPP */

 #elif defined(_M68K)	/* Motorola 68K */
  #define _D0		0	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	1	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3ffe	/* 80/128 long double bits */
  #define _LOFF		15	/* 80/128 long double bits */
  #define _FPP_TYPE	_FPP_M68K	/* Motorola 68xxx FPP */

 #elif defined(_SH4_) || defined(__sh) || defined(__sh__)	/* SH4 */

  #if defined(__BIG_ENDIAN__) || defined(_SH4)
   #define _D0		0	/* 0: big endian, 3: little endian floating-point */

  #else /* __BIG_ENDIAN__ etc. */
   #define _D0		3	/* 0: big endian, 3: little endian floating-point */
  #endif /* __BIG_ENDIAN__ etc. */

  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3fe	/* 64 long double bits */
  #define _LOFF		4	/* 64 long double bits */
  #define _FPP_TYPE	_FPP_SH4	/* Renesas SH4 FPP */

 #elif defined(_M_IA64)	/* IA64 */
  #define _D0		3	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3fe	/* 64 long double bits */
  #define _LOFF		4	/* 64 long double bits */
  #define _FPP_TYPE	_FPP_IA64	/* Intel IA64 FPP */

 #elif defined(__x86_64) /* 64-Bit GCC */
  #define _D0		3	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	1	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3ffe	/* 80/128 long double bits */	
  #define _LOFF		15	/* 80/128 long double bits */
  #define _FPP_TYPE	_FPP_X86	/* Pentium FPP */

 #elif defined(_M_X64) /* 64-Bit x86 VC++ */
  #define _D0		3	/* 0: big endian, 3: little endian floating-point */
  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */
  #define _LBIAS	0x3fe	/* 64 long double bits */
  #define _LOFF		4	/* 64 long double bits */
  #define _FPP_TYPE	_FPP_WIN	/* Pentium FPP under Windows */

 #else /* unknown compilation environment, guess big-endian */
   #if defined(__RX)
     #define _MACH_PDT	long
     #define _MACH_SZT	unsigned long
    #if defined(__LIT)
     #define _D0		3	/* little endian floating-point */
    #else
     #define _D0		0	/* big endian floating-point */
    #endif
	#define _FPP_TYPE	_FPP_RX
   #elif defined(_R_SHC)
     #define _MACH_PDT	int
     #define _MACH_SZT	unsigned long
    #if defined(_LIT)
     #define _D0		3	/* little endian */
    #else
     #define _D0		0	/* big endian */
    #endif
    #if defined(_SH2E) || defined(_SH2AFPU) || defined(_SH4) || defined(_SH4A)
     #define _FPP_TYPE	_FPP_SH4
    #endif
   #elif defined(__H8__)
    #if __DATA_ADDRESS_SIZE__ == 4
     #define _MACH_PDT	long
     #define _MACH_SZT	unsigned long
    #else /* __DATA_ADDRESS_SIZE__ == 4 */
     #define _MACH_PDT	int
     #define _MACH_SZT	unsigned int
    #endif /* __DATA_ADDRESS_SIZE__ == 4 */
     #define _D0		0	/* big endian */
   #elif defined(_R_M16C)
    #if defined(__PTRDIFFT_16__)
     #define _MACH_PDT	signed int
    #else
     #define _MACH_PDT	signed long
    #endif
    #if defined(__SIZET_16__)
     #define _MACH_SZT	unsigned int
    #else
     #define _MACH_SZT	unsigned long
    #endif
     #define _D0	3	/* little endian */
   #else /* __RX */
    #define _D0		0	/* 0: big endian, 3: little endian floating-point */
   #endif /* __RX */
  #define _DLONG	0	/* 0: 64, 1: 80, 2: 128 long double bits */

  #if defined(__RX) && defined(__DBL4)
    #define _LBIAS	0x7e	/* 32 long double bits */
    #define _LOFF	    7	/* 32 long double bits */
  #else /* defined(__RX) && defined(__DBL4) */
    #define _LBIAS	0x3fe	/* 64 long double bits */
    #define _LOFF		4	/* 64 long double bits */
  #endif /* defined(__RX) && defined(__DBL4) */

 #endif /* system detector */

		/* DETERMINE _Ptrdifft AND _Sizet FROM MACHINE TYPE */

 #if defined(_MACH_I32)
typedef _MACH_I32 _Int32t;
typedef unsigned _MACH_I32 _Uint32t;

 #else /* defined(_MACH_I32) */
typedef long _Int32t;
typedef unsigned long _Uint32t;
 #endif /* defined(_MACH_I32) */

 #if defined(_LP64) || defined(__x86_64)
typedef long _Ptrdifft;

 #elif defined(_M_X64)
typedef __int64 _Ptrdifft;

 #elif defined(_MACH_PDT)
typedef _MACH_PDT _Ptrdifft;

 #else /* defined(_MACH_PDT) */
typedef int _Ptrdifft;
 #endif /* defined(_LP64) */

 #if defined(_LP64) || defined(__x86_64)
typedef unsigned long _Sizet;

 #elif defined(_MACH_SZT)
typedef _MACH_SZT _Sizet;

 #else /* defined(_MACH_SZT) */
typedef unsigned int _Sizet;
 #endif /* defined(_LP64) */

 #if defined(__x86_64)
  #define _LLONG	1	/* 64-bit longs */
  #define _RSIZE_MAX	((unsigned int)(-1) >> 1)

 #else /* defined(__x86_64) */
  #define _LLONG	0	/* 32-bit longs */
  #define _RSIZE_MAX	((_Sizet)(-1) >> 1)	/* or sizeof largest object */
 #endif /* defined(__x86_64) */

 #if defined(__linux) || defined(__linux__)
  #define _LINUX_C_LIB	1	/* Linux-specific conventions */
 #endif /* defined(__linux) etc. */

  #define _HAS_POSIX_C_LIB	1	/* use common Unix/Linux conventions */

 #if !defined(_HAS_C9X) && defined(_C99)
  #define _HAS_C9X	1
 #else
  #define _HAS_C9X	0
 #endif /* !defined(_HAS_C9X) etc. */

 #if !defined(_ECPP) && defined(_ABRCPP)
  #define _ECPP
 #endif /* !defined(_ECPP) && defined(_ABRCPP) */

 #if _HAS_C9X && __EDG__ && !defined(__cplusplus)
  #define _HAS_C9X_IMAGINARY_TYPE	1

 #else /* _HAS_C9X etc. */
  #define _HAS_C9X_IMAGINARY_TYPE	0
 #endif /* _HAS_C9X etc. */

 #if !defined(_IS_EMBEDDED) && defined(_ECPP)
  #define _IS_EMBEDDED	1	/* 1 for Embedded C++ */
 #else
  #define _IS_EMBEDDED	0	/* 0 for Embedded C++ */
 #endif /* _IS_EMBEDDED etc. */

 #ifndef __STDC_VERSION__

  #if _HAS_C9X
   #define __STDC_VERSION__	199901L

  #else /* _HAS_C9X */
    #define __STDC_VERSION__	199409L
  #endif /* _HAS_C9X */

 #endif /* __STDC_VERSION__ */

		/* EXCEPTION CONTROL */
 #ifndef _HAS_EXCEPTIONS
  #ifndef _NO_EX	/* don't simplify */
   #define _HAS_EXCEPTIONS	1	/* 1 for try/throw logic */

  #else	/* _NO_EX */
   #define _HAS_EXCEPTIONS	0
  #endif /* _NO_EX */

 #endif /* _HAS_EXCEPTIONS */

		/* NAMING PROPERTIES */
/* #define _STD_LINKAGE	define C names as extern "C++" */
/* #define _STD_USING	define C names in one of three namespaces */

 #ifndef _HAS_NAMESPACE
  #ifndef _NO_NS	/* don't simplify */
   #define _HAS_NAMESPACE	1	/* 1 for C++ names in std */

  #else	/* _NO_NS */
   #define _HAS_NAMESPACE	0
  #endif /* _NO_NS */

 #endif /* _HAS_NAMESPACE */

 #if !defined(_STD_USING) && defined(__cplusplus) \
	&& (defined(_C_IN_NS) || 1 < _ALT_NS)
  #define _STD_USING	/* *.h headers export C names to global */

 #elif defined(_STD_USING) && !defined(__cplusplus)
  #undef _STD_USING	/* define only for C++ */
 #endif /* !defined(_STD_USING) */

 #if !defined(_HAS_STRICT_LINKAGE) \
	&& (__EDG__)
#ifdef __RX
  #define _HAS_STRICT_LINKAGE	0	/* extern "C" in function type */
#else /* __RX */
  #define _HAS_STRICT_LINKAGE	1	/* extern "C" in function type */
#endif /* __RX */
 #endif /* !defined(_HAS_STRICT_LINKAGE) */

		/* THREAD AND LOCALE CONTROL */
 #ifndef _MULTI_THREAD

   #ifndef _NO_MT
    #define _MULTI_THREAD	1	/* 0 for no thread locks */

   #else
    #define _MULTI_THREAD	0
   #endif	/* _NO_MT */

 #endif /* _MULTI_THREAD */

#define _GLOBAL_LOCALE	0	/* 0 for per-thread locales, 1 for shared */
#define _FILE_OP_LOCKS	0	/* 0 for no FILE locks, 1 for atomic */
#define _IOSTREAM_OP_LOCKS	0	/* 0 for no iostream locks, 1 for atomic */

		/* THREAD-LOCAL STORAGE */
#define _COMPILER_TLS	0	/* 1 if compiler supports TLS directly */
#define _TLS_QUAL	/* TLS qualifier, such as __declspec(thread), if any */

 #if !defined(_ADDED_C_LIB)
  #define _ADDED_C_LIB	1	/* include declarations for C extensions */
 #endif /* !defined(_ADDED_C_LIB) */

 #if !defined(_HAS_FIXED_POINT)
  #define _HAS_FIXED_POINT	1	/* enable fixed-point extensions */
 #endif /* !defined(_HAS_FIXED_POINT) */

 #if !defined(_HAS_IMMUTABLE_SETS)
  #define _HAS_IMMUTABLE_SETS	1	/* disallow alterable set elements */
 #endif /* !defined(_HAS_IMMUTABLE_SETS) */

 #if !defined(_HAS_ITERATOR_DEBUGGING) \
	&& (defined(_STL_DB) || defined(_STLP_DEBUG))
  #define _HAS_ITERATOR_DEBUGGING	1	/* enable range checks, etc. */
 #endif /* define _HAS_ITERATOR_DEBUGGING */

 #if !defined(_HAS_STRICT_CONFORMANCE)
  #define _HAS_STRICT_CONFORMANCE	0	/* enable nonconforming extensions */
 #endif /* !defined(_HAS_STRICT_CONFORMANCE) */

 #if !defined(_HAS_TRADITIONAL_IOSTREAMS)
  #define _HAS_TRADITIONAL_IOSTREAMS	1	/* enable old iostreams stuff */
 #endif /* !defined(_HAS_TRADITIONAL_IOSTREAMS) */

 #if !defined(_HAS_TRADITIONAL_ITERATORS)
  #define _HAS_TRADITIONAL_ITERATORS	0	/* don't use pointer iterators */
 #endif /* !defined(_HAS_TRADITIONAL_ITERATORS) */

 #if !defined(_HAS_TRADITIONAL_POS_TYPE)
  #define _HAS_TRADITIONAL_POS_TYPE	0	/* make streampos same as streamoff */
 #endif /* !defined(_HAS_TRADITIONAL_POS_TYPE) */

 #if !defined(_HAS_TRADITIONAL_STL)
  #define _HAS_TRADITIONAL_STL	1	/* enable older STL extensions */
 #endif /* !defined(_HAS_TRADITIONAL_STL) */

 #if !defined(_HAS_TR1)
  #define _HAS_TR1	(!_IS_EMBEDDED)	/* enable TR1 extensions */
 #endif /* !defined(_HAS_TR1) */

#define _HAS_TR1_DECLARATIONS	_HAS_TR1

 #if !defined(_USE_EXISTING_SYSTEM_NAMES)
  #define _USE_EXISTING_SYSTEM_NAMES	1	/* _Open => open, etc.  */
 #endif /* !defined(_USE_EXISTING_SYSTEM_NAMES) */

 #if __STDC_WANT_SAFER_LIB__
  #define __STDC_SAFER_LIB__	200510L
 #endif /* __STDC_WANT_SAFER_LIB__ */


		/* NAMESPACE CONTROL */

 #if defined(__cplusplus)

 #if _HAS_NAMESPACE
namespace std {}

 #if defined(_C_AS_CPP)
  #define _NO_CPP_INLINES	/* just for compiling C library as C++ */
 #endif /* _C_AS_CPP */

 #if 0 < _ALT_NS

  #if defined(_C_AS_CPP)	/* define library in _Dinkum_std */
   #define _STD_BEGIN	namespace _Dinkum_std {_C_LIB_DECL
   #define _STD_END		_END_C_LIB_DECL }

  #else /* _C_AS_CPP */
   #define _STD_BEGIN	namespace _Dinkum_std {
   #define _STD_END		}
  #endif /* _C_AS_CPP */

  #if _ALT_NS == 1	/* define C library in global namespace */
    #define _C_STD_BEGIN
    #define _C_STD_END
    #define _CSTD		::
    #define _STD			::_Dinkum_std::

  #elif _ALT_NS == 2	/* define both C and C++ in namespace _Dinkum_std */
    #define _C_STD_BEGIN	namespace _Dinkum_std {
    #define _C_STD_END	}
    #define _CSTD		::_Dinkum_std::
    #define _STD			::_Dinkum_std::

  #else	/* define C in namespace _Dinkum_std_c and C++ in _Dinkum_std */
    #define _C_STD_BEGIN	namespace _Dinkum_std_c {
    #define _C_STD_END	}
    #define _CSTD		::_Dinkum_std_c::
    #define _STD			::_Dinkum_std::
  #endif /* _ALT_NS */

namespace _Dinkum_std {}
namespace _Dinkum_std_c {}
namespace std {
	using namespace _Dinkum_std;
	using namespace _Dinkum_std_c;
	}

 #elif defined(_STD_USING)

  #if defined(_C_AS_CPP)	/* define library in std */
   #define _STD_BEGIN	namespace std {_C_LIB_DECL
   #define _STD_END		_END_C_LIB_DECL }

  #else /* _C_AS_CPP */
   #define _STD_BEGIN	namespace std {
   #define _STD_END		}
  #endif /* _C_AS_CPP */

   #define _C_STD_BEGIN	namespace std {
   #define _C_STD_END	}
   #define _CSTD		::std::
   #define _STD			::std::

 #else /* _ALT_NS == 0 && !defined(_STD_USING) */

  #if defined(_C_AS_CPP)	/* define C++ library in std, C in global */
   #define _STD_BEGIN	_C_LIB_DECL
   #define _STD_END		_END_C_LIB_DECL

  #else /* _C_AS_CPP */
   #define _STD_BEGIN	namespace std {
   #define _STD_END		}
  #endif /* _C_AS_CPP */

   #define _C_STD_BEGIN
   #define _C_STD_END
   #define _CSTD		::
   #define _STD			::std::
 #endif /* _ALT_NS etc */

  #define _X_STD_BEGIN	namespace std {
  #define _X_STD_END	}
  #define _XSTD			::std::

  #if defined(_STD_USING) && _ALT_NS < 3
   #undef _GLOBAL_USING		/* C names in std namespace */

  #else
   #define _GLOBAL_USING	1	/* c* headers import C names to std */
  #endif /* defined(_STD_USING) */

  #if defined(_STD_LINKAGE)
   #define _C_LIB_DECL		extern "C++" {	/* C has extern "C++" linkage */

  #else /* defined(_STD_LINKAGE) */
   #define _C_LIB_DECL		extern "C" {	/* C has extern "C" linkage */
  #endif /* defined(_STD_LINKAGE) */

  #define _END_C_LIB_DECL	}
  #define _EXTERN_C			extern "C" {
  #define _END_EXTERN_C		}

 #else /* _HAS_NAMESPACE */
  #define _STD_BEGIN
  #define _STD_END
  #define _STD	::

  #define _X_STD_BEGIN
  #define _X_STD_END
  #define _XSTD	::

  #define _C_STD_BEGIN
  #define _C_STD_END
  #define _CSTD	::

  #define _C_LIB_DECL		extern "C" {
  #define _END_C_LIB_DECL	}
  #define _EXTERN_C			extern "C" {
  #define _END_EXTERN_C		}
 #endif /* _HAS_NAMESPACE */

 #else /* __cplusplus */
  #define _STD_BEGIN
  #define _STD_END
  #define _STD

  #define _X_STD_BEGIN
  #define _X_STD_END
  #define _XSTD

  #define _C_STD_BEGIN
  #define _C_STD_END
  #define _CSTD

  #define _C_LIB_DECL
  #define _END_C_LIB_DECL
  #define _EXTERN_C
  #define _END_EXTERN_C
 #endif /* __cplusplus */

 #if 199901L <= __STDC_VERSION__

 #if defined(__cplusplus)
  #define _Restrict

 #else /* defined(__cplusplus) */
  #define _Restrict restrict
 #endif /* defined(__cplusplus) */

 #else /* 199901L <= __STDC_VERSION__ */
 #define _Restrict
 #endif /* 199901L <= __STDC_VERSION__ */

 #ifdef __cplusplus
_STD_BEGIN
typedef bool _Bool;
_STD_END
 #endif /* __cplusplus */

#include <stdarg.h>

		/* VC++ COMPILER PARAMETERS */
 #define _CRTIMP
 #define _CDECL

 #ifdef __NO_LONG_LONG

 #else /* defined(__NO_LONG_LONG) */
  #define _LONGLONG	long long
  #define _ULONGLONG	unsigned long long
  #define _LLONG_MAX	0x7fffffffffffffffLL
  #define _ULLONG_MAX	0xffffffffffffffffULL
 #endif /* __NO_LONG_LONG */

		/* FLOATING-POINT PROPERTIES */
#if defined(__RX) && defined(__DBL4)
  #define _DBIAS	0x7e	/* IEEE format double and float */
  #define _DOFF	7
#else /* defined(__RX) && defined(__DBL4) */
  #define _DBIAS	0x3fe	/* IEEE format double and float */
  #define _DOFF	4
#endif /* defined(__RX) && defined(__DBL4) */

#define _FBIAS	0x7e
#define _FOFF	7

		/* INTEGER PROPERTIES */
#define _BITS_BYTE	8
#define _C2			1	/* 0 if not 2's complement */
#define _MBMAX		8	/* MB_LEN_MAX */

  #if defined(__H8__) || defined(_R_M16C)
    #define _ILONG		0	/* 16-bit int */
  #elif defined(_R_SHC) || defined(__RX)
    #define _ILONG		1	/* 32-bit int */
  #else
    #define _ILONG		1	/* 0 if 16-bit int */
  #endif

 #if defined(__s390__) || defined(__CHAR_UNSIGNED__)  \
	|| defined(_CHAR_UNSIGNED) \
	|| (defined(__RX) && defined(__UCHAR))
  #define _CSIGN	0	/* 0 if char is not signed */

 #else /* defined(__s390__) etc */
  #define _CSIGN	1
 #endif /* defined(__s390__) etc */

#define _MAX_EXP_DIG	8	/* for parsing numerics */
#define _MAX_INT_DIG	32
#define _MAX_SIG_DIG	48

 #if defined(_LONGLONG)
typedef _LONGLONG _Longlong;
typedef _ULONGLONG _ULonglong;

 #else /* defined(_LONGLONG) */
typedef long _Longlong;
typedef unsigned long _ULonglong;
 #define _LLONG_MAX		0x7fffffffL
 #define _ULLONG_MAX	0xffffffffUL
 #endif /* defined(_LONGLONG) */

		/* wchar_t AND wint_t PROPERTIES */

 #if defined(_WCHAR_T) || defined(_WCHAR_T_DEFINED) \
	|| defined (_MSL_WCHAR_T_TYPE)
  #define _WCHART
 #endif /* defined(_WCHAR_T) || defined(_WCHAR_T_DEFINED) */

 #if defined(_WINT_T)
  #define _WINTT
 #endif /* _WINT_T */

#if defined(__RX) && defined(_R_NO_WIDECHAR)
 /* Dummy */
#else /* defined(__RX) && defined(_R_NO_WIDECHAR) */
 #ifdef __cplusplus
  #define _WCHART
typedef wchar_t _Wchart;
typedef wchar_t _Wintt;
 #endif /* __cplusplus */
#endif /* defined(__RX) && defined(_R_NO_WIDECHAR) */

 #if defined(_MSL_WCHAR_T_TYPE)
  #define _WCMIN	0
  #define _WCMAX	0xffff

  #ifndef __cplusplus
typedef wchar_t _Wchart;
typedef wint_t _Wintt;
  #endif /* __cplusplus */

  #define mbstate_t	_DNK_mbstate_t
  #define wctype_t	_DNK_wctype_t
  #define wint_t	_DNK_wint_t
  #define _MSC_VER	1

 #elif defined(__WCHAR_TYPE__)
  #define _WCMIN	(-_WCMAX - _C2)
  #define _WCMAX	0x7fffffff	/* assume signed 32-bit wchar_t */

  #ifndef __cplusplus
typedef __WCHAR_TYPE__ _Wchart;
typedef __WCHAR_TYPE__ _Wintt;
  #endif /* __cplusplus */

 #else /* default wchar_t/wint_t */
#ifdef __RX
  #define _WCMIN	0
  #define _WCMAX	0xffff
#else
  #define _WCMIN	(-_WCMAX - _C2)
  #define _WCMAX	0x7fffffff
#endif

#if defined(__RX) && defined(_R_NO_WIDECHAR)
typedef unsigned short _Wchart;
typedef unsigned long _Wintt;
#else /* defined(__RX) && defined(_R_NO_WIDECHAR) */
  #ifndef __cplusplus
	#ifdef __RX
typedef unsigned short _Wchart;
typedef unsigned long _Wintt;
	#else /* __RX */
typedef long _Wchart;
typedef long _Wintt;
	#endif /* __RX */
  #endif /* __cplusplus */
#endif /* defined(__RX) && defined(_R_NO_WIDECHAR) */

 #endif /* compiler/library type */

		/* POINTER PROPERTIES */
#define _NULL		0	/* 0L if pointer same as long */

		/* signal PROPERTIES */

#define _SIGABRT	6
#define _SIGMAX		44

		/* stdarg PROPERTIES */
typedef va_list _Va_list;

 #if _HAS_C9X

 #if __EDG__ && !defined(__x86_64)
  #undef va_copy
 #endif /* __EDG__ */

 #ifndef va_copy
_EXTERN_C
void _Vacopy(va_list *, va_list);
_END_EXTERN_C
  #define va_copy(apd, aps)	_Vacopy(&(apd), aps)
 #endif /* va_copy */

 #endif /* _IS_C9X */

_C_STD_BEGIN
		/* stdlib PROPERTIES */
#define _EXFAIL	1	/* EXIT_FAILURE */

_EXTERN_C
void _Atexit(void (*)(void));
_END_EXTERN_C

		/* stdio PROPERTIES */
#define _FNAMAX	260
#define _FOPMAX	20
#define _TNAMAX	16

 #define _FD_TYPE	signed char
  #define _FD_NO(str) ((str)->_Handle)
 #define _FD_VALID(fd)	(0 <= (fd))	/* fd is signed integer */
 #define _FD_INVALID	(-1)
 #define _SYSCH(x)	x
typedef char _Sysch_t;

		/* STORAGE ALIGNMENT PROPERTIES */

 #if defined(_LP64) || defined(__x86_64)	/* compiler test */
  #define _MEMBND	4U /* 16-byte boundaries (2^^4) */

 #else /* defined(_LP64) etc. */
  #define _MEMBND	3U /* eight-byte boundaries (2^^3) */
 #endif /* defined(_LP64) etc. */

		/* time PROPERTIES */
 #define _CPS	1

#define _TBIAS	((70 * 365LU + 17) * 86400)
_C_STD_END

		/* MULTITHREAD PROPERTIES */

 #if _MULTI_THREAD
_EXTERN_C
void _Locksyslock(int);
void _Unlocksyslock(int);
_END_EXTERN_C

 #else /* _MULTI_THREAD */
  #define _Locksyslock(x)	(void)0
  #define _Unlocksyslock(x)	(void)0
 #endif /* _MULTI_THREAD */

		/* LOCK MACROS */
 #define _LOCK_LOCALE	0
 #define _LOCK_MALLOC	1
 #define _LOCK_STREAM	2
 #define _LOCK_DEBUG	3
 #define _MAX_LOCK		4	/* one more than highest lock number */

 #if _IOSTREAM_OP_LOCKS
  #define _MAYBE_LOCK

 #else /* _IOSTREAM_OP_LOCKS */
  #define _MAYBE_LOCK	\
	if (_Locktype == _LOCK_MALLOC || _Locktype == _LOCK_DEBUG)
 #endif /* _IOSTREAM_OP_LOCKS */

 #ifdef __cplusplus
_STD_BEGIN
extern "C++" {	// in case of _C_AS_CPP
		// CLASS _Lockit
class _Lockit
	{	// lock while object in existence -- MUST NEST
public:

  #if !_MULTI_THREAD
	_Lockit()
		{	// do nothing
		}

	explicit _Lockit(int)
		{	// do nothing
		}

	~_Lockit()
		{	// do nothing
		}

  #else /* !_MULTI_THREAD */
	_Lockit()
		: _Locktype(_LOCK_MALLOC)
		{	// set default lock
		_MAYBE_LOCK
			_Locksyslock(_Locktype);
		}

	explicit _Lockit(int _Type)
		: _Locktype(_Type)
		{	// set the lock
		_MAYBE_LOCK
			_Locksyslock(_Locktype);
		}

	~_Lockit()
		{	// clear the lock
		_MAYBE_LOCK
			_Unlocksyslock(_Locktype);
		}
  #endif /* _MULTI_THREAD */

//private:
	_Lockit(const _Lockit&);			// not defined
	_Lockit& operator=(const _Lockit&);	// not defined

private:
	int _Locktype;
	};

  #if !_MULTI_THREAD || !_IOSTREAM_OP_LOCKS
class _Mutex
	{	// lock under program control
public:
	void _Lock()
		{	// do nothing
		}

	void _Unlock()
		{	// do nothing
	}
	};

  #else /* !_MULTI_THREAD || !_IOSTREAM_OP_LOCKS */
class _Mutex
	{	// lock under program control
public:
	_Mutex();
	~_Mutex();
	void _Lock();
	void _Unlock();

private:
	_Mutex(const _Mutex&);				// not defined
	_Mutex& operator=(const _Mutex&);	// not defined
	void *_Mtx;
	};
  #endif /* !_MULTI_THREAD || !_IOSTREAM_OP_LOCKS */

}	// extern "C++"
_STD_END
 #endif /* __cplusplus */

		/* MISCELLANEOUS MACROS */
#define _ATEXIT_T	void

#ifndef _TEMPLATE_STAT
 #define _TEMPLATE_STAT
#endif /* */

  #define _NO_RETURN(fun)	void fun

#endif /* _YVALS */


/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
