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

/*****************************************************************/
/* SPEC ;                                                        */
/*   NAME = stdarg :                                             */
/*   FUNC = this module do the following finctions ;             */
/*                                                               */
/*         (1) initialize parameter pointer                      */
/*         (2) set parameter pointer to next parameter           */
/*                                                               */
/*                                                               */
/*   END ;                                                       */
/*****************************************************************/

#ifndef _STDARG_H
#define _STDARG_H
#include <macro.h>

#if defined(__H8__)

typedef char *va_list ;

#define va_start(AP,LASTARG) ((void)(AP = ((va_list)&LASTARG + ((sizeof(LASTARG)+1)&~1))))

#define va_arg(AP,TYPE) \
  (AP += ((sizeof(TYPE)+1)&~1), *((TYPE *)(AP - ((sizeof(TYPE)+1)&~1))))

#define va_end(ap)

#endif /* __H8__ */

#if defined(_R_SHC) || defined(__RX)

typedef char *va_list ;

#if defined(__RX)
#ifdef __cplusplus
extern "C" {
#endif
void __builtin_va_start(va_list);
#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */
#define va_start(AP,LASTARG) __builtin_va_start(AP)
#else /* __RX */
#define va_start(AP,LASTARG) ((void)(AP = ((va_list)&LASTARG + ((sizeof(LASTARG)+3)&~3))))
#endif /* __RX */

#define va_arg(AP,TYPE) \
  (AP += ((sizeof(TYPE)+3)&~3), *((TYPE *)(AP - ((sizeof(TYPE)+3)&~3))))

#define va_end(ap)

#endif /* _R_SHC || __RX */

#if defined(_R_M16C)

#ifndef _VA_LIST_DEF
typedef char *va_list;
#define _VA_LIST_DEF
#endif

#define va_arg(AP,TYPE) (AP += sizeof(TYPE), *((TYPE *)(AP - sizeof(TYPE))))
#define va_end(AP) (AP = (va_list)0)
#define va_start(AP,LASTARG) (AP = ((va_list)&LASTARG + sizeof(LASTARG)))

#endif /* _R_M16C */

#endif /* _STDARG_H */
