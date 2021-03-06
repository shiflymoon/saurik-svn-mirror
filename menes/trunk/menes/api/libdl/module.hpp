/* Menes - C++ High-Level Utility Library
 * Copyright (C) 2003-2005  Jay Freeman (saurik)
*/

/*
 *        Redistribution and use in source and binary
 * forms, with or without modification, are permitted
 * provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the
 *    above copyright notice, this list of conditions
 *    and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the
 *    above copyright notice, this list of conditions
 *    and the following disclaimer in the documentation
 *    and/or other materials provided with the
 *    distribution.
 * 3. The name of the author may not be used to endorse
 *    or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MENES_API_LIBDL_MODULE_HPP
#define MENES_API_LIBDL_MODULE_HPP

#include "cxx/platform.hpp"
#include "api/linkage.hpp"

#ifdef MENES_PRAGMA_ONCE
#pragma once
#endif

#include "api/libdl/error.hpp"
#include "ext/refcount.hpp"

#include <dlfcn.h>

namespace api {
namespace libdl {

class Module :
    public ext::ReferenceCounted
{
  public:
    enum Type {
        Extension,
        Object
    };

  protected:
    void *handle_;

  public:
    explicit Module(const cse::String &path, Type type) {
        // XXX: mightn't be RTLD_LAZY
        handle_ = ::dlopen(path.NullTerminate(), RTLD_NOW | (type == Object ? RTLD_LOCAL : RTLD_GLOBAL));
        if (handle_ == NULL)
            throw Error();
    }

    virtual ~Module() {
        if (::dlclose(handle_) != 0)
            throw Error();
    }

    void *operator [](const cse::String &name) {
        // XXX: should I _really_ clear this? not report it?
        ::dlerror();

        void *symbol(::dlsym(handle_, name.NullTerminate()));
        if (const char *error = ::dlerror())
            throw Error(error);
        return symbol;
    }
};

} }

#endif//MENES_API_LIBDL_MODULE_HPP
