/* crypto/gost/gost_err.c */
/* ====================================================================
 * Copyright (c) 1999-2014 The OpenSSL Project.  All rights reserved.
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
#include <openssl/err.h>
#include <openssl/gost.h>

#ifndef OPENSSL_NO_ERR

#define ERR_FUNC(func) ERR_PACK(ERR_LIB_GOST,func,0)
#define ERR_REASON(reason) ERR_PACK(ERR_LIB_GOST,0,reason)

static ERR_STRING_DATA GOST_str_functs[]= {
	{ERR_FUNC(0xfff), "CRYPTO_internal"},
	{0, NULL}
};

static ERR_STRING_DATA GOST_str_reasons[] = {
	{ERR_REASON(GOST_R_BAD_KEY_PARAMETERS_FORMAT),"bad key parameters format"},
	{ERR_REASON(GOST_R_BAD_PKEY_PARAMETERS_FORMAT),"bad pkey parameters format"},
	{ERR_REASON(GOST_R_CANNOT_PACK_EPHEMERAL_KEY),"cannot pack ephemeral key"},
	{ERR_REASON(GOST_R_CTRL_CALL_FAILED)     ,"ctrl call failed"},
	{ERR_REASON(GOST_R_ERROR_COMPUTING_SHARED_KEY),"error computing shared key"},
	{ERR_REASON(GOST_R_ERROR_PARSING_KEY_TRANSPORT_INFO),"error parsing key transport info"},
	{ERR_REASON(GOST_R_INCOMPATIBLE_ALGORITHMS),"incompatible algorithms"},
	{ERR_REASON(GOST_R_INCOMPATIBLE_PEER_KEY),"incompatible peer key"},
	{ERR_REASON(GOST_R_INVALID_DIGEST_TYPE)  ,"invalid digest type"},
	{ERR_REASON(GOST_R_INVALID_IV_LENGTH)    ,"invalid iv length"},
	{ERR_REASON(GOST_R_INVALID_MAC_KEY_LENGTH),"invalid mac key length"},
	{ERR_REASON(GOST_R_KEY_IS_NOT_INITIALIZED),"key is not initialized"},
	{ERR_REASON(GOST_R_KEY_PARAMETERS_MISSING),"key parameters missing"},
	{ERR_REASON(GOST_R_MAC_KEY_NOT_SET)      ,"mac key not set"},
	{ERR_REASON(GOST_R_NO_PARAMETERS_SET)    ,"no parameters set"},
	{ERR_REASON(GOST_R_NO_PEER_KEY)          ,"no peer key"},
	{ERR_REASON(GOST_R_NO_PRIVATE_PART_OF_NON_EPHEMERAL_KEYPAIR),"no private part of non ephemeral keypair"},
	{ERR_REASON(GOST_R_PUBLIC_KEY_UNDEFINED) ,"public key undefined"},
	{ERR_REASON(GOST_R_RANDOM_NUMBER_GENERATOR_FAILED),"random number generator failed"},
	{ERR_REASON(GOST_R_SIGNATURE_MISMATCH)   ,"signature mismatch"},
	{ERR_REASON(GOST_R_SIGNATURE_PARTS_GREATER_THAN_Q),"signature parts greater than q"},
	{ERR_REASON(GOST_R_UKM_NOT_SET)          ,"ukm not set"},
	{0, NULL}
};
#endif

void
ERR_load_GOST_strings(void) {
#ifndef OPENSSL_NO_ERR
	if (ERR_func_error_string(GOST_str_functs[0].error) == NULL) {
		ERR_load_strings(0,GOST_str_functs);
		ERR_load_strings(0,GOST_str_reasons);
	}
#endif
}
