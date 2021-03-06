/* Menes - C++ High-Level Utility Library
 * Copyright (C) 2002-2004  Jay Freeman (saurik)
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

#ifndef MENES_API_POSIX_ERROR_HPP
#define MENES_API_POSIX_ERROR_HPP

#include "cxx/platform.hpp"
#include "api/linkage.hpp"

#ifdef MENES_PRAGMA_ONCE
#pragma once
#endif

#include "api/error.hpp"

#include <errno.h>

namespace api {
namespace Posix {

_finline int CheckError(int status);

struct API_DECLARE ApiTraits  :
    public ErrorTraits<int>
{
    static const unsigned ErrorBase = 10;

    static const char *GetName()  { return "POSIX"; }

    static ErrorCode GetLastError() {
        return errno;
    }

    static cse::String GetMessage(const ErrorCode &code) {
        // XXX: this buffer is not big enough
        char buffer[1024];

// XXX: detect this correctly
#if defined(_WIN32)
        CheckError(::strerror_s(buffer, sizeof(buffer), code));
#elif defined(__GLIBC__)
        return ext::Buffer(::strerror_r(code, buffer, sizeof(buffer)));
#else
        CheckError(::strerror_r(code, buffer, sizeof(buffer)));
#endif

        return ext::Buffer(buffer);
    }
};

API_DECLARE typedef ErrorImpl<ApiTraits> Error;

_finline int CheckError(int status) {
    if (status == -1)
        throw Error();
    return status;
}

} }

#endif//MENES_API_POSIX_ERROR_HPP
