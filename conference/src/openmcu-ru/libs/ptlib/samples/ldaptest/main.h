/*
 * main.h
 *
 * PWLib application header file for LDAP Test
 *
 * Copyright (c) 2003 Equivalence Pty. Ltd.
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
 * Contributor(s): ______________________________________.
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
 * Revision 1.3  2006/06/21 03:28:42  csoutheren
 * Various cleanups thanks for Frederic Heem
 *
 * Revision 1.2  2003/03/31 03:35:20  robertj
 * Major addition of LDAP functionality.
 * Added ILS specialisation of LDAP.
 *
 * Revision 1.1  2003/03/28 01:15:44  robertj
 * OpenLDAP support.
 *
 */

#ifndef _LDAPTest_MAIN_H
#define _LDAPTest_MAIN_H

#include <ptlib/pprocess.h>

class PLDAPSession;
class PILSSession;


class LDAPTest : public PProcess
{
  PCLASSINFO(LDAPTest, PProcess)

  public:
    LDAPTest();
    virtual void Main();
    void Usage();
    void Add(PArgList & args, PLDAPSession & ldap);
    void Delete(PArgList & args, PLDAPSession & ldap);
    void Search(PArgList & args, PLDAPSession & ldap);

    void AddILS(PArgList & args, PILSSession & ils);
    void DeleteILS(PArgList & args, PILSSession & ils);
    void SearchILS(PArgList & args, PILSSession & ils);
};


#endif  // _LDAPTest_MAIN_H


// End of File ///////////////////////////////////////////////////////////////
