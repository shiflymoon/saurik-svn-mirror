/* Menes Optimization - C++ Profiling and Verification
 * Copyright (C) 2003-2004  Jay Freeman (saurik)
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

#ifndef MENES_SZF_SAVELOAD_STL_HPP
#define MENES_SZF_SAVELOAD_STL_HPP

#include "cxx/platform.hpp"

#ifdef MENES_PRAGMA_ONCE
#pragma once
#endif

#include "szf/method.hpp"
#include "szf/saveload.hpp"

#include <map>
#include <string>
#include <vector>

namespace szf {

SZF_DECLARE void Save(Method *method, std::string value, const char *name);
SZF_DECLARE void Load(Method *method, std::string &value, const char *name);

template <typename First_, typename Second_>
void Save(Method *method, const std::pair<First_, Second_> &value, const char *name) {
    method->OpenScope(name);
    Save(method, value.first, "first");
    Save(method, value.second, "second");
    method->CloseScope();
}

template <typename First_, typename Second_>
void Load(Method *method, std::pair<First_, Second_> &value, const char *name) {
    method->OpenScope(name);
    Load(method, value.first, "first");
    Load(method, value.second, "second");
    method->CloseScope();
}

template <typename Key_, typename Elem_>
void Save(Method *method, const std::map<Key_, Elem_> &value, const char *name) {
    method->OpenScope(name);

    Save(method, value.size(), "size");
    for (typename std::map<Key_, Elem_>::const_iterator i(value.begin()); i != value.end(); ++i)
        Save(method, *i, "element");

    method->CloseScope();
}

template <typename Key_, typename Elem_>
void Load(Method *method, std::map<Key_, Elem_> &value, const char *name) {
    method->OpenScope(name);

    size_t size;
    Load(method, size, "size");

    for (typename std::map<Key_, Elem_>::const_iterator i(value.begin()); i != value.end(); ++i) {
        std::pair<Key_, Elem_> element;
        Load(method, element, "element");
        value.insert(element);
    }

    method->CloseScope();
}

template <typename Elem_>
void Save(Method *method, const std::vector<Elem_> &value, const char *name) {
    method->OpenScope(name);

    Save(method, value.size(), "size");
    for (typename ext::Vector<Elem_>::const_iterator i(value.begin()); i != value.end(); ++i)
        Save(method, *i, "element");

    method->CloseScope();
}

template <typename Elem_>
void Load(Method *method, std::vector<Elem_> &value, const char *name) {
    method->OpenScope(name);

    size_t size;
    Load(method, size, "size");
    value.resize(size);

    for (typename ext::Vector<Elem_>::iterator i(value.begin()); i != value.end(); ++i)
        Load(method, *i, "element");

    method->CloseScope();
}

}

#endif//MENES_SZF_SAVELOAD_STL_HPP
