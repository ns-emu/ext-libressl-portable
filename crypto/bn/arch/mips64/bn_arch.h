/*	$OpenBSD: bn_arch.h,v 1.7 2023/01/23 12:17:58 jsing Exp $ */
/*
 * Copyright (c) 2023 Joel Sing <jsing@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef HEADER_BN_ARCH_H
#define HEADER_BN_ARCH_H

#ifndef OPENSSL_NO_ASM

#define HAVE_BN_ADD_WORDS

#define HAVE_BN_DIV_WORDS
#define HAVE_BN_DIV_3_WORDS

#define HAVE_BN_MUL_ADD_WORDS
#define HAVE_BN_MUL_COMBA4
#define HAVE_BN_MUL_COMBA8
#define HAVE_BN_MUL_WORDS

#define HAVE_BN_SQR_COMBA4
#define HAVE_BN_SQR_COMBA8
#define HAVE_BN_SQR_WORDS

#define HAVE_BN_SUB_WORDS

#endif
#endif
