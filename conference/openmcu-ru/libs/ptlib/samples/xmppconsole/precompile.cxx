/*
 * precompile.cxx
 *
 * PWLib application source file for XMPPConsole
 *
 * Originally from the XMPPTest module, copied here by Derek Smithies.
 *
 * Precompiled header generation file.
 *
 * Copyright 2004 Reitek S.p.A.
 *
 * $Log: precompile.cxx,v $
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
 * Revision 1.1  2005/08/04 03:29:12  dereksmithies
 * Initial release of a console application to test XMPP messages between running applications.
 * Thanks to Indranet Technologies ltd for sponsoring the work.
 * Thanks to Federico Pinna & Reitek S.p.A for the inital work of getting XMPP going.
 *
 *
 *
 *  Commit log from XMPPTest
 * Revision 1.1  2004/04/26 01:51:58  rjongbloed
 * More implementation of XMPP, thanks a lot to Federico Pinna & Reitek S.p.A.
 *
 *
 */

#include <ptlib.h>


// End of File ///////////////////////////////////////////////////////////////
