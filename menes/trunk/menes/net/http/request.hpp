/* Menes - C++ High-Level Utility Library
 * Copyright (C) 2004-2005  Jay Freeman (saurik)
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

#ifndef MENES_NET_HTTP_REQUEST_HPP
#define MENES_NET_HTTP_REQUEST_HPP

#include "cxx/platform.hpp"
#include "net/linkage.hpp"

#ifdef MENES_PRAGMA_ONCE
#pragma once
#endif

#include "api/socket.hpp"
#include "cse/string.hpp"
#include "ios/types.hpp"

#include "net/http/headers.hpp"
#include "net/http/uri.hpp"
#include "net/http/version.hpp"

#include "net/mime/document.hpp"

namespace net {
namespace Http {

class Request {
  private:
    mutable _R<net::Mime::Document> document_;

  public:
    cse::String method_;
    Uri uri_;
    Version version_;
    Headers headers_;
    _R<ios::Reader> content_;
    api::Address client_;

  public:
    _R<net::Mime::Document> GetDocument() const {
        if (!document_.IsEmpty())
            return document_;
        else if (content_.IsEmpty())
            return _R<net::Mime::Document>();
        else {
            cse::String type(headers_["Content-Type"][0]);
            document_ = net::Mime::Document::Parse(type, content_);
            return document_;
        }
    }
};

} }

#endif//MENES_NET_HTTP_REQUEST_HPP