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

#ifndef _H_C_LIB
#define _H_C_LIB
#include <macro.h>

#ifdef __cplusplus
extern "C"{
#endif
extern void _CALL_INIT(void); /* for global class object initial processing */
extern void _CALL_END(void);  /* for global class object post-processing */
extern void _INITSCT(void);   /* Clear BSS, and copy DATA from ROM to RAM */
#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

#endif /* #ifndef _H_C_LIB */
