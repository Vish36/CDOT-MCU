/*
 * pdirect.h
 *
 * File system directory class.
 *
 * Portable Windows Library
 *
 * Copyright (c) 1993-1998 Equivalence Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Portable Windows Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Portions are Copyright (C) 1993 Free Software Foundation, Inc.
 * All Rights Reserved.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: pdirect.h,v $
 * Revision 1.1.1.1  2020/01/20 06:09:07  bishnu
 * conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
 * It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
 * CDOT-MCU works as service provider (roomNo@serviceIP:Port)
 * room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.
 *
 * For more Details go through the 'conferncing_Overview-mod' document
 *
 * Revision 1.1.1.1  2020/01/14 11:23:54  root
 * Final version of CDOT-MCU
 *
 * Revision 1.1.1.1  2020/01/14 08:43:31  root
 * Final changes for the CDOT-MCU
 *
 * Revision 1.1.1.1  2019/12/19 09:12:34  root
 *
 * CDOT-MCU  conferencing module
 *
 *
 * Revision 1.1  2000/06/26 11:17:19  robertj
 * Nucleus++ port (incomplete).
 *
 * Revision 1.9  1999/03/09 08:52:25  robertj
 * Changes caused by documentation frenzy.
 *
 * Revision 1.8  1998/11/30 22:06:53  robertj
 * New directory structure.
 *
 * Revision 1.7  1998/11/24 09:38:16  robertj
 * FreeBSD port.
 *
 * Revision 1.6  1998/11/10 12:59:05  robertj
 * Fixed strange problems with readdir_r usage.
 *
 * Revision 1.5  1998/11/05 10:33:53  robertj
 * Solaris compatibility.
 *
 * Revision 1.4  1998/11/05 09:58:30  craigs
 * Added static buffer for reentrant routines
 *
 * Revision 1.3  1998/09/24 04:11:43  robertj
 * Added open software license.
 *
 * Revision 1.2  1996/08/03 12:08:19  craigs
 * Changed for new common directories
 *
 * Revision 1.1  1995/01/23 18:43:27  craigs
 * Initial revision
 *
 * Revision 1.1  1994/04/12  08:31:05  robertj
 * Initial revision
 *
 */

#ifndef _PDIRECTORY

#ifndef __NUCLEUS_MNT__
#pragma interface
#endif

///////////////////////////////////////////////////////////////////////////////
// PDirectory

#if 0
#ifndef __NUCLEUS_MNT__
#include <dirent.h>
#endif
#endif

#include <limits.h>

#define PDIR_SEPARATOR '/'

#define P_MAX_PATH    (_POSIX_PATH_MAX)

typedef PString PFilePathString;

#include "../../pdirect.h"
  protected:
};

#endif


