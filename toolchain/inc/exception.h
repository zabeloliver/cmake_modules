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

/***********************************************************************/
/* SPEC;                                                               */
/*  NAME = exception.h :                                               */
/*                                                                     */
/*  FUNC = Include file for exception handling (see 18.6)              */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/

#ifndef _EXCEPTION_H
#define _EXCEPTION_H

/* This lets users disable the EDG supplied exception classes. */
#ifndef __NO_EDG_EXCEPTION_CLASSES

#ifdef __EDG_RUNTIME_USES_NAMESPACES
namespace std {
#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */
  class exception {
  public:
    exception() throw();
    exception(const exception&) throw();
    exception& operator=(const exception&) throw();
    virtual ~exception() throw();
    virtual const char* what() const throw();
  };

  /*
  If bool is not supported, use a typedef for bool.
  */
  #ifdef _BOOL
  typedef bool __bool;
  #else /* ifndef _BOOL */
  typedef int __bool;
  #endif /* ifdef _BOOL */

  class bad_exception : public exception {
  public:
    bad_exception() throw();
    bad_exception(const bad_exception&) throw();
    bad_exception& operator=(const bad_exception&) throw();
    virtual ~bad_exception() throw();
    virtual const char* what() const throw();
  };

  typedef void (*terminate_handler)();
  extern terminate_handler set_terminate(terminate_handler) throw();

  typedef void (*unexpected_handler)();
  extern unexpected_handler set_unexpected(unexpected_handler) throw();

  /* unexpected and terminate are in the WP definition of exception.h.
     It is not clear why. */
  void terminate();
  void unexpected();

  extern __bool uncaught_exception() throw();

#ifdef __EDG_RUNTIME_USES_NAMESPACES
}  /* namespace */

#ifdef __EDG_IMPLICIT_USING_STD
/* Implicitly include a using directive for the STD namespace when this
   preprocessing flag is TRUE. */
using namespace std;
#endif /* ifdef __EDG_IMPLICIT_USING_STD */

#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

#endif /* ifndef __NO_EDG_EXCEPTION_CLASSES */

#endif /* _EXCEPTION_H */
