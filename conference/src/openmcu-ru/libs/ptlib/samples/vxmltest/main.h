/*
 * main.h
 *
 * PWLib application header file for vxmltest
 *
 * Copyright 2002 Equivalence
 *
 * $Log: main.h,v $
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
 * Revision 1.3  2006/06/21 03:28:43  csoutheren
 * Various cleanups thanks for Frederic Heem
 *
 * Revision 1.2  2004/06/02 08:30:22  csoutheren
 * Tweaks to avoid some problems with reading single bytes from a PCM stream
 *
 * Revision 1.1  2002/08/06 05:26:33  craigs
 * Initial version
 *
 */

#ifndef _Vxmltest_MAIN_H
#define _Vxmltest_MAIN_H

#include <ptlib/pprocess.h>

class PVXMLSession;

class Vxmltest : public PProcess
{
  PCLASSINFO(Vxmltest, PProcess)

  public:
    Vxmltest();
    void Main();
    PDECLARE_NOTIFIER(PThread, Vxmltest, InputThread);

  protected:
    BOOL inputRunning;
    PVXMLSession * vxml;
};


#endif  // _Vxmltest_MAIN_H


// End of File ///////////////////////////////////////////////////////////////
