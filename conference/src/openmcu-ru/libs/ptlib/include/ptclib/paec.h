/*
 * paec.h
 *
 * Open Phone Abstraction Library (OPAL)
 * Formally known as the Open H323 project.
 *
 * Copyright (c) 2004 Post Increment
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
 * The author of this code is Damien Sandras
 *
 * rewritten amd made generic ptlib by Simon Horne
 *
 * Contributor(s): Miguel Rodriguez Perez
 *
 * $Log: paec.h,v $
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
 * Revision 1.5  2007/03/15 21:35:21  shorne
 * fix for buffer underrun
 *
 * Revision 1.4  2007/03/06 00:22:48  shorne
 * Changed to a buffering type arrangement
 *
 * Revision 1.3  2007/02/18 18:39:21  shorne
 * Added PWaitAndSignal
 *
 * Revision 1.2  2006/02/26 09:27:49  shorne
 * Renamed AEC class name, moved to seperate library
 *
 * Revision 1.1  2006/01/26 08:05:03  shorne
 * Added AEC support
 *
 */

#ifndef __OPAL_ECHOCANCEL_H
#define __OPAL_ECHOCANCEL_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <ptclib/qchannel.h>

/** This class implements Acoustic Echo Cancellation
  * The principal is to copy to a buffer incoming audio.
  * after it has been decoded and when recording the audio 
  * to remove the echo pattern from the incoming audio 
  * prior to sending to the enooder..
  */

PQUEUE(ReceiveTimeQueue, PTimeInterval);

struct SpeexEchoState;
struct SpeexPreprocessState;
class PAec : public PObject
{
  PCLASSINFO(PAec, PObject);
public:

  /**@name Construction */
  //@{
  /**Create a new canceler.
   */
     PAec(int _clock = 8000, int _sampletime = 30);
     ~PAec();
  //@}

  /**@@name Basic operations */
  //@{
  /**Recording Channel. Should be called prior to encoding audio
   */
    void Send(BYTE * buffer, unsigned & length);

  /**Playing Channel  Should be called after decoding and prior to playing.
   */
    void Receive(BYTE * buffer, unsigned & length);
  //@}

protected:
  PMutex readwritemute;
  PQueueChannel *echo_chan;
  SpeexEchoState *echoState;
  SpeexPreprocessState *preprocessState;
  int clockrate;                      // Frame Rate default 8000hz for narrowband audio
  int bufferTime;                     // Time between receiving and Transmitting   
  PInt64 minbuffer;                   // minbuffer (in milliseconds)
  PInt64 maxbuffer;                   // maxbuffer (in milliseconds)
  int sampleTime;                     // Length of each sample
  ReceiveTimeQueue rectime;           // Queue of timestamps for ensure read/write in sync
  PTimeInterval lastTimeStamp;        // LastTimeStamp of recieved data
  BOOL receiveReady;
  void *ref_buf;
  void *echo_buf;
  void *e_buf;
  void *noise;

};

#endif // __OPAL_ECHOCANCEL_H

/////////////////////////////////////////////////////////////////////////////
