/* pop3-response.c - POP3 responses
 * Copyright (C) 2001  Bruce Guenter <bruceg@em.ca> or FutureQuest, Inc.
 * Development of this program was sponsored by FutureQuest, Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Contact information:
 * FutureQuest Inc.
 * PO BOX 623127
 * Oviedo FL 32762-3127 USA
 * http://www.FutureQuest.net/
 * ossi@FutureQuest.net
 */
#include <stdlib.h>
#include <string.h>
#include "iobuf/iobuf.h"
#include "pop3.h"

const char err_internal[] = "-ERR Internal error.";
const char err_unimpl[] = "-ERR Unimplemented.";
const char ok[] = "+OK ";
const char err_syntax[] = "-ERR Syntax error.";

void respond(const char* msg)
{
  if (!obuf_puts(&outbuf, msg) ||
      !obuf_putc(&outbuf, CR) ||
      !obuf_putc(&outbuf, LF) ||
      !obuf_flush(&outbuf))
    exit(1);
}