/* $OpenBSD: dso_err.c,v 1.10 2022/07/12 14:42:49 kn Exp $ */
/* ====================================================================
 * Copyright (c) 1999-2006 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openssl-core@OpenSSL.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */

#include <stdio.h>

#include <openssl/opensslconf.h>

#include <openssl/err.h>
#include <openssl/dso.h>

#ifndef OPENSSL_NO_ERR

#define ERR_FUNC(func) ERR_PACK(ERR_LIB_DSO,func,0)
#define ERR_REASON(reason) ERR_PACK(ERR_LIB_DSO,0,reason)

static ERR_STRING_DATA DSO_str_functs[]= {
	{ERR_FUNC(0xfff), "CRYPTO_internal"},
	{0, NULL}
};

static ERR_STRING_DATA DSO_str_reasons[]= {
	{ERR_REASON(DSO_R_CTRL_FAILED)           , "control command failed"},
	{ERR_REASON(DSO_R_DSO_ALREADY_LOADED)    , "dso already loaded"},
	{ERR_REASON(DSO_R_EMPTY_FILE_STRUCTURE)  , "empty file structure"},
	{ERR_REASON(DSO_R_FAILURE)               , "failure"},
	{ERR_REASON(DSO_R_FILENAME_TOO_BIG)      , "filename too big"},
	{ERR_REASON(DSO_R_FINISH_FAILED)         , "cleanup method function failed"},
	{ERR_REASON(DSO_R_INCORRECT_FILE_SYNTAX) , "incorrect file syntax"},
	{ERR_REASON(DSO_R_LOAD_FAILED)           , "could not load the shared library"},
	{ERR_REASON(DSO_R_NAME_TRANSLATION_FAILED), "name translation failed"},
	{ERR_REASON(DSO_R_NO_FILENAME)           , "no filename"},
	{ERR_REASON(DSO_R_NO_FILE_SPECIFICATION) , "no file specification"},
	{ERR_REASON(DSO_R_NULL_HANDLE)           , "a null shared library handle was used"},
	{ERR_REASON(DSO_R_SET_FILENAME_FAILED)   , "set filename failed"},
	{ERR_REASON(DSO_R_STACK_ERROR)           , "the meth_data stack is corrupt"},
	{ERR_REASON(DSO_R_SYM_FAILURE)           , "could not bind to the requested symbol name"},
	{ERR_REASON(DSO_R_UNLOAD_FAILED)         , "could not unload the shared library"},
	{ERR_REASON(DSO_R_UNSUPPORTED)           , "functionality not supported"},
	{0, NULL}
};

#endif

void
ERR_load_DSO_strings(void)
{
#ifndef OPENSSL_NO_ERR
	if (ERR_func_error_string(DSO_str_functs[0].error) == NULL) {
		ERR_load_strings(0, DSO_str_functs);
		ERR_load_strings(0, DSO_str_reasons);
	}
#endif
}
