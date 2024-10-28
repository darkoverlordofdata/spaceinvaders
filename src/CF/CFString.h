/*
 * Copyright (c) 2012, Jonathan Schleifer <js@webkeks.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once
#include "CFClass.h"
#include "CFRange.h"

typedef struct __CFRefPool* CFRefPoolRef;
typedef struct __CFString* CFStringRef;

extern size_t   CFStrnLen(const char*, size_t);
extern char*    CFStrDup(const char*);
extern char*    CFStrnDup(const char*, size_t);

extern CFClassRef CFString;
extern char*    CFString_C(CFStringRef);
extern size_t   CFString_Length(CFStringRef);
extern bool     CFString_Set(CFStringRef, const char*);
extern void     CFString_SetNoCopy(CFStringRef, char*, size_t);
extern bool     CFString_Append(CFStringRef, CFStringRef);
extern bool     CFString_AppendC(CFStringRef, const char*);
extern bool     CFString_HasPrefix(CFStringRef, CFStringRef);
extern bool     CFString_HasPrefixC(CFStringRef, const char*);
extern bool     CFString_HasSuffix(CFStringRef, CFStringRef);
extern bool     CFString_HasSuffixC(CFStringRef, const char*);
extern size_t   CFString_Find(CFStringRef, CFStringRef, CFRange);
extern size_t   CFString_FindC(CFStringRef, const char*, CFRange);

