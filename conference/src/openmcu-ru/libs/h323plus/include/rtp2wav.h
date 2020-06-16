/*
 * rfc28rtp2wav33.h
 *
 * Open Phone Abstraction Library (OPAL)
 * Formally known as the Open H323 project.
 *
 * Copyright (c) 2001 Equivalence Pty. Ltd.
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
 * The Original Code is Open Phone Abstraction Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: rtp2wav.h,v $
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
 * Revision 1.1  2007/08/06 20:50:50  shorne
 * First commit of h323plus
 *
 * Revision 1.4  2003/01/07 07:53:00  craigs
 * Fixed problem with multi-frame G.723.1 packets
 *
 * Revision 1.3  2002/09/16 01:14:15  robertj
 * Added #define so can select if #pragma interface/implementation is used on
 *   platform basis (eg MacOS) rather than compiler, thanks Robert Monaghan.
 *
 * Revision 1.2  2002/05/23 04:22:29  robertj
 * Fixed problem with detecting correct payload type. Must
 *   wait for first non-empty packet.
 * Added virtual function so can override record start point.
 *
 * Revision 1.1  2002/05/21 02:42:58  robertj
 * Added class to allow for saving of RTP data to a WAV file.
 *
 */

#ifndef __RTP_RTP2WAV_H
#define __RTP_RTP2WAV_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif


#include <ptclib/pwavfile.h>
#include "rtp.h"


///////////////////////////////////////////////////////////////////////////////

/**This class encapsulates a WAV file that can be used to intercept RTP data
   in the standard H323RTPChannel class.
  */
class OpalRtpToWavFile : public PWAVFile
{
    PCLASSINFO(OpalRtpToWavFile, PWAVFile);
  public:
    OpalRtpToWavFile();
    OpalRtpToWavFile(
      const PString & filename
    );

    virtual BOOL OnFirstPacket(RTP_DataFrame & frame);

    const PNotifier & GetReceiveHandler() const { return receiveHandler; }

  protected:
    PDECLARE_NOTIFIER(RTP_DataFrame, OpalRtpToWavFile, ReceivedPacket);

    PNotifier                   receiveHandler;
    RTP_DataFrame::PayloadTypes payloadType;
    PBYTEArray                  lastFrame;
    PINDEX                      lastPayloadSize;
};


#endif // __RTP_RTP2WAV_H


/////////////////////////////////////////////////////////////////////////////
