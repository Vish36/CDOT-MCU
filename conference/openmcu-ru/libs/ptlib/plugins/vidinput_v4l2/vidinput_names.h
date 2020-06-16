/*
 * vidinput_names.h
 *
 * Classes to support streaming video input (grabbing) and output.
 *
 * Portable Windows Library
 *
 * Copyright (c) 1993-2000 Equivalence Pty. Ltd.
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
 * The Original Code is Portable Windows Library (V4L plugin).
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): Derek Smithies (derek@indranet.co.nz)
 *                 Mark Cooke (mpc@star.sr.bham.ac.uk)
 *                 Nicola Orru' <nigu@itadinanta.it>
 *
 * $Log: vidinput_names.h,v $
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
 * Revision 1.2  2004/11/07 22:48:47  dominance
 * fixed copyright of v4l2 plugin. Last commit's credits go to Nicola Orru' <nigu@itadinanta.it> ...
 *
 */
#ifndef _VIDINPUTNAMES_H
#define _VIDINPUTNAMES_H


#include <ptlib.h>
#include <ptlib/videoio.h>
#ifndef MAJOR
#define MAJOR(a) (int)((unsigned short) (a) >> 8)
#endif

#ifndef MINOR
#define MINOR(a) (int)((unsigned short) (a) & 0xFF)
#endif

class V4LXNames : public PObject
{ 
  PCLASSINFO(V4LXNames, PObject);

 public:

  V4LXNames() {/* nothing */};

  virtual void Update () = 0;
  
  PString GetUserFriendly(PString devName);

  PString GetDeviceName(PString userName);

  PStringList GetInputDeviceNames();

protected:

  void AddUserDeviceName(PString userName, PString devName);

  virtual PString BuildUserFriendly(PString devname) = 0;

  void PopulateDictionary();

  void ReadDeviceDirectory(PDirectory devdir, POrdinalToString & vid);

  PMutex          mutex;
  PStringToString deviceKey;
  PStringToString userKey;
  PStringList     inputDeviceNames;

};

#endif
