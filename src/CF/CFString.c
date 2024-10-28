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

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "CFObject.h"
#include "CFString.h"
#include "CFHash.h"

struct __CFString {
	struct __CFObject obj;
	char *data;
	size_t len;
};

size_t
CFStrnLen(const char *s, size_t max)
{
	size_t i = 0;

	for (i = 0; i < max && *s != '\0'; s++)
		i++;

	return i;
}

char*
CFStrDup(const char *s)
{
	char *copy;
	size_t len;

	len = strlen(s);

	if ((copy = malloc(len + 1)) == NULL)
		return NULL;

	memcpy(copy, s, len + 1);

	return copy;
}

char*
CFStrnDup(const char *s, size_t max)
{
	char *copy;
	size_t len;

	len = CFStrnLen(s, max);

	if ((copy = malloc(len + 1)) == NULL)
		return NULL;

	memcpy(copy, s, len);
	copy[len] = 0;

	return copy;
}

static bool
ctor(void *ptr, va_list args)
{
	CFStringRef str = ptr;
	const char *cstr = va_arg(args, const char*);

	if (cstr != NULL) {
		str->data = NULL;
		if ((str->data = CFStrDup(cstr)) == NULL)
			return false;

		str->len = strlen(cstr);
	} else {
		str->data = NULL;
		str->len = 0;
	}

	return true;
}

static void
dtor(void *ptr)
{
	CFStringRef str = ptr;

	if (str->data != NULL)
		free(str->data);
}

static bool
equal(void *ptr1, void *ptr2)
{
	CFObjectRef obj2 = ptr2;
	CFStringRef str1, str2;

	if (obj2->cls != CFString)
		return false;

	str1 = ptr1;
	str2 = ptr2;

	if (str1->len != str2->len)
		return false;

	return !memcmp(str1->data, str2->data, str1->len);
}

static uint32_t
hash(void *ptr)
{
	CFStringRef str = ptr;
	size_t i;
	uint32_t hash;

	CF_HASH_INIT(hash);

	for (i = 0; i < str->len; i++)
		CF_HASH_ADD(hash, str->data[i]);

	CF_HASH_FINALIZE(hash);

	return hash;
}

static void*
copy(void *ptr)
{
	CFStringRef str = ptr;
	CFStringRef new;

	if ((new = CFNew(CFString, (void*)NULL)) == NULL)
		return NULL;

	if ((new->data = malloc(str->len + 1)) == NULL) {
		CFUnref(new);
		return NULL;
	}
	new->len = str->len;

	memcpy(new->data, str->data, str->len + 1);

	return new;
}

char*
CFString_C(CFStringRef str)
{
	return str->data;
}

size_t
CFString_Length(CFStringRef string)
{
	return string->len;
}

bool
CFString_Set(CFStringRef str, const char *cstr)
{
	char *copy;
	size_t len;

	if (str != NULL) {
		if ((copy = CFStrDup(cstr)) == NULL)
			return false;

		len = strlen(copy);
	} else {
		copy = NULL;
		len = 0;
	}

	if (str->data != NULL)
		free(str->data);

	str->data = copy;
	str->len = len;

	return true;
}

void
CFString_SetNoCopy(CFStringRef str, char *cstr, size_t len)
{
	if (str->data != NULL)
		free(str->data);

	str->data = cstr;
	str->len = len;
}

bool
CFString_Append(CFStringRef str, CFStringRef append)
{
	char *new;

	if (append == NULL)
		return true;

	if ((new = realloc(str->data, str->len + append->len + 1)) == NULL)
		return false;

	memcpy(new + str->len, append->data, append->len);
	new[str->len + append->len] = 0;

	str->data = new;
	str->len += append->len;

	return true;
}

bool
CFString_AppendC(CFStringRef str, const char *append)
{
	char *new;
	size_t append_len;

	if (append == NULL)
		return true;

	append_len = strlen(append);

	if ((new = realloc(str->data, str->len + append_len + 1)) == NULL)
		return false;

	memcpy(new + str->len, append, append_len);
	new[str->len + append_len] = 0;

	str->data = new;
	str->len += append_len;

	return true;
}

bool
CFString_HasPrefix(CFStringRef str, CFStringRef prefix)
{
	if (prefix->len > str->len)
		return false;

	return !memcmp(str->data, prefix->data, prefix->len);
}

bool
CFString_HasPrefixC(CFStringRef str, const char *prefix)
{
	size_t prefix_len = strlen(prefix);

	if (prefix_len > str->len)
		return false;

	return !memcmp(str->data, prefix, prefix_len);
}

bool
CFString_HasSuffix(CFStringRef str, CFStringRef suffix)
{
	if (suffix->len > str->len)
		return false;

	return !memcmp(str->data, suffix->data, suffix->len);
}

bool
CFStringHas_SuffixC(CFStringRef str, const char *suffix)
{
	size_t suffix_len = strlen(suffix);

	if (suffix_len > str->len)
		return false;

	return !memcmp(str->data, suffix, suffix_len);
}

size_t
CFString_Find(CFStringRef str, CFStringRef substr, CFRange range)
{
	long i;

	if (range.start > (long)str->len)
		return SIZE_MAX;

	if (range.length == (long)SIZE_MAX)
		range.length = (long)str->len - range.start;

	if (range.start + range.length > (long)str->len || (long)substr->len > range.length)
		return SIZE_MAX;

	for (i = range.start; i <= range.start + range.length - (long)substr->len;
	    i++)
		if (!memcmp(str->data + i, substr->data, substr->len))
			return (size_t)i;

	return SIZE_MAX;
}

size_t
CFString_FindC(CFStringRef str, const char *substr, CFRange range)
{
	size_t substr_len = strlen(substr);
	long i;

	if (range.start > (long)str->len)
		return SIZE_MAX;

	if (range.length == (long)SIZE_MAX)
		range.length = (long)str->len - range.start;

	if (range.start + range.length > (long)str->len || (long)substr_len > range.length)
		return SIZE_MAX;

	for (i = range.start; i <= range.start + range.length - (long)substr_len;
	    i++)
		if (!memcmp(str->data + i, substr, substr_len))
			return (size_t)i;

	return SIZE_MAX;
}

static struct __CFClass class = {
	.name = "CFString",
	.size = sizeof(struct __CFString),
	.ctor = ctor,
	.dtor = dtor,
	.equal = equal,
	.hash = hash,
	.copy = copy
};
CFClassRef CFString = &class;
