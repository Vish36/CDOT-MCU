/*
 * t120proto.h
 *
 * T.120 protocol handler
 *
 * Open Phone Abstraction Library
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
 * The Original Code is Open H323 Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: t120proto.h,v $
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
 * Revision 1.4  2002/09/16 01:14:15  robertj
 * Added #define so can select if #pragma interface/implementation is used on
 *   platform basis (eg MacOS) rather than compiler, thanks Robert Monaghan.
 *
 * Revision 1.3  2002/09/03 05:44:46  robertj
 * Normalised the multi-include header prevention ifdef/define symbol.
 * Added globally accessible functions for media format name.
 * Added standard TCP port constant.
 *
 * Revision 1.2  2002/02/01 01:47:02  robertj
 * Some more fixes for T.120 channel establishment, more to do!
 *
 * Revision 1.1  2001/07/17 04:44:29  robertj
 * Partial implementation of T.120 and T.38 logical channels.
 *
 */

#ifndef __OPAL_T120PROTO_H
#define __OPAL_T120PROTO_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif


#include "mediafmt.h"


class H323Transport;

class X224;
class MCS_ConnectMCSPDU;
class MCS_DomainMCSPDU;


///////////////////////////////////////////////////////////////////////////////

/**This class describes the T.120 protocol handler.
 */
class OpalT120Protocol : public PObject
{
    PCLASSINFO(OpalT120Protocol, PObject);
  public:
    enum {
      DefaultTcpPort = 1503
    };

    static OpalMediaFormat const MediaFormat;


  /**@name Construction */
  //@{
    /**Create a new protocol handler.
     */
    OpalT120Protocol();
  //@}

  /**@name Operations */
  //@{
    /**Handle the origination of a T.120 connection.
      */
    virtual BOOL Originate(
      H323Transport & transport
    );

    /**Handle the origination of a T.120 connection.
      */
    virtual BOOL Answer(
      H323Transport & transport
    );

    /**Handle incoming T.120 connection.

       If returns FALSE, then the reading loop should be terminated.
      */
    virtual BOOL HandleConnect(
      const MCS_ConnectMCSPDU & pdu
    );

    /**Handle incoming T.120 packet.

       If returns FALSE, then the reading loop should be terminated.
      */
    virtual BOOL HandleDomain(
      const MCS_DomainMCSPDU & pdu
    );
  //@}
};


#endif // __OPAL_T120PROTO_H


/////////////////////////////////////////////////////////////////////////////
