<?xml version="1.0"?>

<!-- Menes - C++ High-Level Utility Library
   - Copyright (C) 2004  Jay Freeman (saurik)
-->

<!--
   -        Redistribution and use in source and binary
   - forms, with or without modification, are permitted
   - provided that the following conditions are met:
   -
   - 1. Redistributions of source code must retain the
   -    above copyright notice, this list of conditions
   -    and the following disclaimer.
   - 2. Redistributions in binary form must reproduce the
   -    above copyright notice, this list of conditions
   -    and the following disclaimer in the documentation
   -    and/or other materials provided with the
   -    distribution.
   - 3. The name of the author may not be used to endorse
   -    or promote products derived from this software
   -    without specific prior written permission.
   -
   - THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS''
   - AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
   - BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   - MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   - ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE
   - LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   - EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
   - NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   - SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   - INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   - LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
   - TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
   - ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
   - ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
-->

<xsl:stylesheet version="2.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xmlns:fn="http://www.w3.org/2003/11/xpath-functions"
    xmlns:xdt="http://www.w3.org/2003/11/xpath-datatypes"
    xmlns:xpp="http://www.saurik.com/menes/xpp/0.9"
    xmlns:bnf="http://www.saurik.com/menes/bnf/0.9"
    exclude-result-prefixes="xsl xs xsi fn xdt xpp"
>

<xsl:include href="../../menes/bnf/utility.xsl"/>
<xsl:include href="../../menes/xpp/sequence.xsl"/>

<xsl:template name="split">
    <xsl:param name="string" as="xs:string"/>

    <xsl:if test="string-length($string) ne 0">
        <bnf:string value="{substring($string, 1, 1)}"/>

        <xsl:call-template name="split">
            <xsl:with-param name="string" select="substring($string, 2)"/>
        </xsl:call-template>
    </xsl:if>
</xsl:template>

<xsl:template match="bnf:string">
    <xsl:call-template name="split">
        <xsl:with-param name="string" select="@value"/>
    </xsl:call-template>
</xsl:template>

<xsl:template match="@*|node()">
    <xsl:copy>
        <xsl:apply-templates select="@*|node()"/>
    </xsl:copy>
</xsl:template>

</xsl:stylesheet>