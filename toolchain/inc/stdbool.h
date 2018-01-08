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

/* stdbool.h standard header */
#ifndef _STDBOOL
#define _STDBOOL
#include <macro.h>
#ifndef _YVALS
#include <sys/yvals.h>
#endif /* _YVALS */

_C_STD_BEGIN

 #define __bool_true_false_are_defined	1

 #ifndef __cplusplus
		/* TYPES */

 #if 199901L <= __STDC_VERSION__

 #else /* 199901L <= __STDC_VERSION__ */
typedef unsigned long _Bool;
 #endif /* 199901L <= __STDC_VERSION__ */

		/* MACROS */
 #define bool	_Bool
 #define false	0
 #define true	1
 #endif /* __cplusplus */

_C_STD_END
#endif /* _STDBOOL */

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
V5.03:0216 */
