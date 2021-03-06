/* Menes - C++ High-Level Utility Library
 * Copyright (C) 2004  Jay Freeman (saurik)
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

#ifndef MENES_ALG_MAXIMAL_HPP
#define MENES_ALG_MAXIMAL_HPP

#include "cxx/platform.hpp"
#include "alg/linkage.hpp"

#ifdef MENES_PRAGMA_ONCE
#pragma once
#endif

namespace alg {

template <typename Type_>
class Maximal {
  private:
    typedef Maximal<Type_> This_;

    Type_ current_;
    Type_ maximum_;
    Type_ total_;

    void Update_() {
        if (maximum_ < current_)
            maximum_ = current_;
    }

  public:
    Maximal() :
        current_(),
        maximum_(current_),
        total_()
    {
    }

    Maximal(const Type_ &value) :
        current_(value),
        maximum_(current_),
        total_()
    {
    }

    This_ &operator =(const Type_ &rhs) {
        Type_ diff(rhs - current_);
        if (0 < diff)
            total_ += diff;

        current_ = rhs;
        Update_();
        return *this;
    }

    This_ &operator +=(const Type_ &rhs) {
        current_ += rhs;
        total_ += rhs;
        Update_();
        return *this;
    }

    This_ &operator -=(const Type_ &rhs) {
        current_ -= rhs;
        return *this;
    }

    This_ &operator ++() {
        ++current_;
        ++total_;
        Update_();
        return *this;
    }

    This_ &operator --() {
        --current_;
        return *this;
    }

    const Type_ &GetMaximum() const {
        return maximum_;
    }

    const Type_ &GetTotal() const {
        return total_;
    }

    operator const Type_ &() const {
        return current_;
    }
};

}

#endif//MENES_ALG_MAXIMAL_HPP
