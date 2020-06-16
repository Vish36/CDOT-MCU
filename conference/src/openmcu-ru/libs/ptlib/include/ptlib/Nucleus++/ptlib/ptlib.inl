/*
 * osutil.inl
 *
 * Operating System classes inline function implementation
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
 * $Log: ptlib.inl,v $
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
 * Revision 1.2  2002/06/27 06:44:46  robertj
 * Changed "" to PString::Empty() where assigning to PString.
 *
 * Revision 1.1  2000/06/26 11:17:20  robertj
 * Nucleus++ port (incomplete).
 *
 * Revision 1.18  1998/11/24 09:38:22  robertj
 * FreeBSD port.
 *
 * Revision 1.17  1998/11/10 12:59:18  robertj
 * Fixed strange problems with readdir_r usage.
 *
 * Revision 1.16  1998/10/18 10:02:47  robertj
 * Fixed program argument access functions.
 *
 * Revision 1.15  1998/09/24 04:11:49  robertj
 * Added open software license.
 *
 */

#if defined(P_LINUX)
#if (__GNUC_MINOR__ < 7)
#include <localeinfo.h>
#else
#define P_USE_LANGINFO
#endif
#elif defined(P_HPUX9)
#define P_USE_LANGINFO
#elif defined(P_SUN4)
#endif

#ifdef P_USE_LANGINFO
#include <langinfo.h>
#endif

PINLINE DWORD PProcess::GetProcessID() const
{
#ifdef __NUCLEUS_PLUS__
// Only one process
  return 0;
#else
  return (DWORD)getpid();
#endif
}

///////////////////////////////////////////////////////////////////////////////

PINLINE unsigned PTimer::Resolution()
#ifdef __NUCLEUS_PLUS__
  {
// Returns number of milliseconds per tick
#pragma message ("Timer tick hard-coded at 10 milliseconds in ptlib.inl")
  return 10;
  }
#elif defined(P_SUN4)
  { return 1000; }
#else
  { return (unsigned)(1000/CLOCKS_PER_SEC); }
#endif

///////////////////////////////////////////////////////////////////////////////


PINLINE PTime::PTime()
{
  theTime = time(NULL);
}


///////////////////////////////////////////////////////////////////////////////

PINLINE BOOL PDirectory::IsRoot() const
#ifdef WOT_NO_FILESYSTEM
  { return TRUE;}
#else
  { return IsSeparator((*this)[0]) && ((*this)[1] == '\0'); }
#endif

PINLINE BOOL PDirectory::IsSeparator(char ch)
  { return ch == PDIR_SEPARATOR; }

#ifdef WOT_NO_FILESYSTEM
PINLINE BOOL PDirectory::Change(const PString &)
  { return TRUE;}

PINLINE BOOL PDirectory::Exists(const PString & p)
  { return FALSE; }
#else
PINLINE BOOL PDirectory::Change(const PString & p)
  { return chdir(p) == 0; }

PINLINE BOOL PDirectory::Exists(const PString & p)
  { return access((const char *)p, 0) == 0; }
#endif

///////////////////////////////////////////////////////////////////////////////

PINLINE PString PFilePath::GetVolume() const
  { return PString::Empty(); }

///////////////////////////////////////////////////////////////////////////////

PINLINE BOOL PFile::Exists(const PFilePath & name)
#ifdef WOT_NO_FILESYSTEM
  { return FALSE; }
#else
  { return access(name, 0) == 0; }
#endif

PINLINE BOOL PFile::Remove(const PFilePath & name, BOOL)
  { return unlink(name) == 0; }

///////////////////////////////////////////////////////////////////////////////

PINLINE void PChannel::Construct()
  { os_handle = -1; }

PINLINE PString PChannel::GetName() const
  { return channelName; }

// End Of File ///////////////////////////////////////////////////////////////
