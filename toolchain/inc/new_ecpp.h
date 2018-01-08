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

//
// Dynamic memory management
// Embeded C++ Library Header <new>
//

//====================================================================
//  File:	new
//  Purpose:	Definition of class new
//  Create:     1997.09.20 Rev. 1.0
//====================================================================

#ifndef _NEW_
#define _NEW_

#include <stdlib.h>

// Storage allocation and deallocation
void *operator new(size_t);
void *operator new[] (size_t);
void *operator new(size_t,void *);
void *operator new[](size_t,void *);

void operator delete(void *);
void operator delete[](void *);
// void operator delete(void *, void *);	// Not implemented
// void operator delete[](void *, void *);	// Not implemented

// Type new_handler
typedef void (*new_handler)();

// set_new_handler
new_handler set_new_handler(new_handler new_P);

// new_handler
extern new_handler _ec2p_new_handler;

#endif
