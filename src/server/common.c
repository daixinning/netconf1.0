/**
 * \file common.c
 * \author Radek Krejci <rkrejci@cesent.cz>
 * \brief Netopeer server operations.
 *
 * Copyright (C) 2011 CESNET, z.s.p.o.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is, and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>

#include <libnetconf.h>

void clb_print(NC_VERB_LEVEL level, const char* msg)
{
	switch (level) {
	case NC_VERB_ERROR:
		//syslog(LOG_ERR, "%s", msg);
		fprintf(stderr, "<LOG_ERR> %s\n", msg);
		break;
	case NC_VERB_WARNING:
		//syslog(LOG_WARNING, "%s", msg);
        fprintf(stderr, "<LOG_WARNING> %s\n", msg);
		break;
	case NC_VERB_VERBOSE:
		//syslog(LOG_INFO, "%s", msg);
        fprintf(stderr, "<LOG_INFO> %s\n", msg);
		break;
	case NC_VERB_DEBUG:
		//syslog(LOG_DEBUG, "%s", msg);
        fprintf(stderr, "<LOG_DEBUG> %s\n", msg);
		break;
    default:
        fprintf(stderr, "<DEFAULT> %s\n", msg);
        break;
	}
}

void print_debug(const char * format, ...)
{
#define MAX_DEBUG_LEN 4096
	char msg[MAX_DEBUG_LEN];
	va_list ap;

	va_start(ap, format);
	vsnprintf(msg, MAX_DEBUG_LEN, format, ap);
	va_end(ap);

	clb_print(NC_VERB_DEBUG, msg);
}


