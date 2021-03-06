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

#ifndef MENES_DBI_PGSQL_STATEMENT_HPP
#define MENES_DBI_PGSQL_STATEMENT_HPP

#include "cxx/platform.hpp"
#include "dbi/linkage.hpp"

#ifdef MENES_PRAGMA_ONCE
#pragma once
#endif

#include "dbi/statement.hpp"

namespace dbi {
namespace PgSql {

class ResultSet;
EXT_HANDLESTUB(class Connection)

class Statement :
    public dbi::Statement
{
  public:
    using dbi::Statement::Execute;
    using dbi::Statement::Set;

  private:
    _R<Connection> connection_;

    typedef ext::Vector<cse::String> Parts_;
    Parts_ statement_;
    Parts_ arguments_;

  public:
    Statement(const _R<Connection> &connection, const cse::String &statement);

    virtual void Set(unsigned index, const ext::Buffer &value);
    virtual void Set(unsigned index, int64_t value);
    virtual void Set(unsigned index, bool value);
    virtual void Set(unsigned index, const cse::String &value);
    virtual void Set(unsigned index, const ext::Uuid &value);
    virtual void Set(unsigned index, const dbi::Blob &value);
    virtual void Set(unsigned index, const Null &value);

    virtual _R<dbi::ResultSet> Execute() const;
};

} }

#endif//MENES_DBI_PGSQL_STATEMENT_HPP
