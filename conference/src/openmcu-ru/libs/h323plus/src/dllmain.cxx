/*
 * dllmain.cxx
 *
 * DLL main entry point for OpenH323.dll
 *
 * Open H323 Library
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
 * The Original Code is Open H323 Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: dllmain.cxx,v $
 * Revision 1.1.1.1  2020/01/20 06:09:03  bishnu
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
 * Revision 1.1.1.1  2020/01/14 08:43:31  root
 * Final changes for the CDOT-MCU
 *
 * Revision 1.1.1.1  2019/12/19 09:12:34  root
 *
 * CDOT-MCU  conferencing module
 *
 *
 * Revision 1.1  2007/08/06 20:51:03  shorne
 * First commit of h323plus
 *
 * Revision 1.3  2002/11/10 23:14:40  robertj
 * Made sure static variables are included in DLL
 *
 * Revision 1.2  2000/05/02 04:32:26  robertj
 * Fixed copyright notice comment.
 *
 * Revision 1.1  2000/04/13 00:02:01  robertj
 * Added ability to create DLL version of library.
 *
 */

#include <ptlib.h>

#define H323_STATIC_LIB
#include <h323.h>


HINSTANCE PDllInstance;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID)
{
  if (fdwReason == DLL_PROCESS_ATTACH)
    PDllInstance = hinstDLL;
  return TRUE;
}

