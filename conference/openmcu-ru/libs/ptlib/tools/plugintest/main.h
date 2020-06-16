/*
 * main.h
 *
 * PWLib application header file for PluginTest
 *
 * Copyright 2003 Equivalence
 *
 * $Log: main.h,v $
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
 * Revision 1.2  2003/11/12 03:35:33  csoutheren
 * Added sound device tests thanks to Derek
 * Added listing of loading plugin types
 *
 * Revision 1.1.2.1  2003/10/07 01:52:39  csoutheren
 * Test program for plugins
 *
 * Revision 1.1  2003/04/15 04:12:38  craigs
 * Initial version
 *
 */

#ifndef _PluginTest_MAIN_H
#define _PluginTest_MAIN_H




class PluginTest : public PProcess
{
  PCLASSINFO(PluginTest, PProcess)

  public:
    PluginTest();
    void Main();
};


#endif  // _PluginTest_MAIN_H


// End of File ///////////////////////////////////////////////////////////////
