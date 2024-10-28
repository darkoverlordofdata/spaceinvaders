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
#include <assert.h>

#include "CFObject.h"
#include "CFRefPool.h"

struct __CFRefPool {
	struct __CFObject obj;
	void **data;
	size_t size;
	CFRefPoolRef prev, next;
};

static CFRefPoolRef top;

static bool
ctor(void *ptr, va_list args)
{
	CFRefPoolRef pool = ptr;
	(void)args;

	pool->data = NULL;
	pool->size = 0;

	if (top != NULL) {
		pool->prev = top;
		top->next = pool;
	} else
		pool->prev = NULL;
	pool->next = NULL;

	top = pool;

	return true;
}

static void
dtor(void *ptr)
{
	CFRefPoolRef pool = ptr;
	size_t i;

	if (pool->next != NULL)
		CFUnref(pool->next);

	for (i = 0; i < pool->size; i++)
		CFUnref(pool->data[i]);

	if (pool->data != NULL)
		free(pool->data);

	top = pool->prev;

	if (top != NULL)
		top->next = NULL;
}

bool
CFRefPool_Add(void *ptr)
{
	void **ndata;

	assert(top != NULL);

	if (top->data != NULL)
		ndata = realloc(top->data, (top->size + 1) * sizeof(void*));
	else
		ndata = malloc((top->size + 1) * sizeof(void*));

	if (ndata == NULL)
		return false;

	ndata[top->size++] = ptr;

	top->data = ndata;

	return true;
}

static struct __CFClass class = {
	.name = "CFRefPool",
	.size = sizeof(struct __CFRefPool),
	.ctor = ctor,
	.dtor = dtor
};
CFClassRef CFRefPool = &class;
