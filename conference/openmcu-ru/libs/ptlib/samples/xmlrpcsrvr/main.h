/*
 * main.h
 *
 * PWLib application header file for xmlrpcsrvr
 *
 * Copyright 2002 Equivalence
 *
 * $Log: main.h,v $
 * Revision 1.1.1.1  2020/01/20 06:08:44  bishnu
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
 * Revision 1.2  2006/06/21 03:28:43  csoutheren
 * Various cleanups thanks for Frederic Heem
 *
 * Revision 1.1  2002/10/02 08:58:20  craigs
 * Initial version
 *
 */

#ifndef _Xmlrpcsrvr_MAIN_H
#define _Xmlrpcsrvr_MAIN_H

#include <ptlib/pprocess.h>
#include <ptclib/httpsvc.h>
#include <ptclib/pxmlrpcs.h>

class Xmlrpcsrvr : public PHTTPServiceProcess
{
  PCLASSINFO(Xmlrpcsrvr, PHTTPServiceProcess)

  public:
    Xmlrpcsrvr();
    void Main();
    BOOL OnStart();
    void OnStop();
    void OnConfigChanged();
    void OnControl();
    PString GetPageGraphic();
    void AddUnregisteredText(PHTML & html);
    BOOL Initialise(const char * initMsg);

    PDECLARE_NOTIFIER(PXMLRPCServerParms, Xmlrpcsrvr, FunctionNotifier);

  protected:
    PXMLRPCServerResource * xmlrpcServer;
};


#endif  // _Xmlrpcsrvr_MAIN_H


// End of File ///////////////////////////////////////////////////////////////
