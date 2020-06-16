/*
 * dllmain.cxx
 *
 * DLL main entry point for PTLib.dll and PWLib.dll
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
 * $Log: dllmain.cxx,v $
 * Revision 1.1.1.1  2020/01/20 06:08:41  bishnu
 * conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
 * It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
 * CDOT-MCU works as service provider (roomNo@serviceIP:Port)
 * room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.
 *
 * For more Details go through the 'conferncing_Overview-mod' document
 *
 * Revision 1.1.1.1  2020/01/14 11:23:53  root
 * Final version of CDOT-MCU
 *
 * Revision 1.1.1.1  2020/01/14 08:43:29  root
 * Final changes for the CDOT-MCU
 *
 * Revision 1.1.1.1  2019/12/19 09:12:34  root
 *
 * CDOT-MCU  conferencing module
 *
 *
 * Revision 1.4  2007/05/19 08:54:45  rjongbloed
 * Further integration of DirectSound plugin thanks to Vincent Luba.and NOVACOM (http://www.novacom.be).
 *
 * Revision 1.3  2005/09/18 13:01:43  dominance
 * fixed pragma warnings when building with gcc.
 *
 * Revision 1.2  2004/10/23 10:53:19  ykiryanov
 * Added ifdef _WIN32_WCE for PocketPC 2003 SDK port
 *
 * Revision 1.1  1998/09/25 11:04:09  craigs
 * Initial revision
 *
 */

#ifdef _MSC_VER
#pragma warning(disable:4201 4514)
#endif

#include <ptbuildopts.h>

#ifdef P_DIRECTSOUND
#define INITGUID
#include <dsound.h>
#endif

#include <windows.h>


#ifndef _WIN32_WCE
HINSTANCE PDllInstance;
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID)
#else
HANDLE PDllInstance;
BOOL WINAPI DllMain(HANDLE hinstDLL, DWORD fdwReason, LPVOID)
#endif
{
  if (fdwReason == DLL_PROCESS_ATTACH)
    PDllInstance = hinstDLL;
  return TRUE;
}

