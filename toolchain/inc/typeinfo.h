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
/*  NAME = typeinfo.h :                                                */
/*                                                                     */
/*  FUNC = Include file for type information (18.5.1)                  */
/*                                                                     */
/*  CLAS = UNIT;                                                       */
/*                                                                     */
/* END;                                                                */
/***********************************************************************/

#ifndef _TYPEINFO_H
#define _TYPEINFO_H

#include <exception.h>

#ifdef __EDG_RUNTIME_USES_NAMESPACES
namespace std {
#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

  /*
  If bool is not supported, use a typedef for bool.
  */
  #ifdef _BOOL
  typedef bool __bool;
  #else /* ifndef _BOOL */
  typedef int __bool;
  #endif /* ifdef _BOOL */

/* The following pragma is used so that the compiler knows that this definition
   of type_info is the one that corresponds to the type returned by typeid. */
#pragma define_type_info
  class type_info {
  public:
    virtual ~type_info();
    __bool operator==(const type_info&) const;
    __bool operator!=(const type_info&) const;
    __bool before(const type_info&) const;
    const char* name() const;
  private:
    type_info& operator=(const type_info&);  // Not actually defined
  protected:
    // Protected instead of private to suppress the "no accessible
    // constructor" warning
    type_info(const type_info&);  // Not actually defined
#ifdef __EDG_IA64_ABI
  private:
    const char *__type_name;
#endif /* ifdef __EDG_IA64_ABI */
  };

  class bad_cast : public exception {
  public:
    bad_cast() throw();
    bad_cast(const bad_cast&) throw();
    bad_cast& operator=(const bad_cast&) throw();
    virtual ~bad_cast() throw();
    virtual const char* what() const throw();
  };

  class bad_typeid : public exception {
  public:
    bad_typeid() throw();
    bad_typeid(const bad_typeid&) throw();
    bad_typeid& operator=(const bad_typeid&) throw();
    virtual ~bad_typeid() throw();
    virtual const char* what() const throw();
  };

#ifdef __EDG_RUNTIME_USES_NAMESPACES
}  /* namespace std */

#ifdef __EDG_IMPLICIT_USING_STD
/* Implicitly include a using directive for the STD namespace when this
   preprocessing flag is TRUE. */
using namespace std;
#endif /* ifdef __EDG_IMPLICIT_USING_STD */

#endif /* ifdef __EDG_RUNTIME_USES_NAMESPACES */

#endif /* _TYPEINFO_H */
