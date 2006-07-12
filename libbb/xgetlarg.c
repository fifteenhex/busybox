/* vi: set sw=4 ts=4: */
/*
 * Copyright (C) 2003-2004 Erik Andersen <andersen@codepoet.org>
 *
 * Licensed under GPLv2 or later, see file LICENSE in this tarball for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <assert.h>
#include <ctype.h>

#include "libbb.h"

long bb_xgetlarg(const char *arg, int base, long lower, long upper)
{
	long result;
	char *endptr;
	int errno_save = errno;

	if (ENABLE_DEBUG && arg==NULL)
		bb_error_msg_and_die("Null in xgetlarg.");

	errno = 0;
	result = strtol(arg, &endptr, base);
	if (errno != 0 || *endptr!='\0' || endptr==arg || result < lower || result > upper)
		bb_show_usage();
	errno = errno_save;
	return result;
}
