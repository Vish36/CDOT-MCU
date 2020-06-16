/*
 * pils.h
 *
 * Microsoft Internet Location Server Protocol interface class.
 *
 * Portable Windows Library
 *
 * Copyright (c) 1993-2003 Equivalence Pty. Ltd.
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
 * $Log: pils.h,v $
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
 * Revision 1.4  2004/02/20 16:27:52  ykiryanov
 * if'd LDAP code to enable non-LDAP builds
 *
 * Revision 1.3  2003/04/11 00:07:46  robertj
 * More for Microsoft IP address specification wierdness (registration side).
 *
 * Revision 1.2  2003/04/07 13:05:09  robertj
 * Workaround for Microsoft IP address specification wierdness.
 *
 * Revision 1.1  2003/03/31 03:35:20  robertj
 * Major addition of LDAP functionality.
 * Added ILS specialisation of LDAP.
 *
 */

#ifndef _PILS_H
#define _PILS_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#if P_LDAP

#include <ptlib/sockets.h>
#include <ptclib/pldap.h>


 /**This class will create an LDAP client to access a remote ILS server.
  */
class PILSSession : public PLDAPSession
{
  PCLASSINFO(PILSSession, PLDAPSession)
  public:
    /**Create an ILS client.
      */
    PILSSession();

    /**Special IP address class. Microsoft in their infinite wisdom save the
       IP address as an little endian integer in the LDAP fild, but this was
       generated from a 32 bit integer that was in network byte order (big
       endian) which causes immense confusion. Reading directly into a
       PIPSocket::Address does not work as it assumes that any integer forms
       would be in host order. So we need to override the standard read
       function so the marchalling into the RTPerson structure works.
       All very sad.
     */
    class MSIPAddress : public PIPSocket::Address
    {
      public:
        MSIPAddress(DWORD a = 0)                    : Address(a) { }
        MSIPAddress(const PIPSocket::Address & a)   : Address(a) { }
        MSIPAddress(const PString & dotNotation)    : Address(dotNotation) { }
        MSIPAddress(PINDEX len, const BYTE * bytes) : Address(len, bytes) { }

        MSIPAddress & operator=(DWORD a)                      { Address::operator=(a); return *this; }
        MSIPAddress & operator=(const PIPSocket::Address & a) { Address::operator=(a); return *this; }
        MSIPAddress & operator=(const PString & dotNotation)  { Address::operator=(dotNotation); return *this; }

      friend istream & operator>>(istream & s, MSIPAddress & a);
      friend ostream & operator<<(ostream & s, MSIPAddress & a);
    };

    PLDAP_STRUCT_BEGIN(RTPerson)
       PLDAP_ATTR_SIMP(RTPerson, PString,     cn); // Must be non-empty
       PLDAP_ATTR_SIMP(RTPerson, PString,     c);
       PLDAP_ATTR_SIMP(RTPerson, PString,     o);
       PLDAP_ATTR_SIMP(RTPerson, PString,     surname);
       PLDAP_ATTR_SIMP(RTPerson, PString,     givenName);
       PLDAP_ATTR_SIMP(RTPerson, PString,     rfc822Mailbox); // Must be non-empty
       PLDAP_ATTR_SIMP(RTPerson, PString,     location);
       PLDAP_ATTR_SIMP(RTPerson, PString,     comment);
       PLDAP_ATTR_SIMP(RTPerson, MSIPAddress, sipAddress);
       PLDAP_ATTR_SIMP(RTPerson, PWORDArray,  sport);
       PLDAP_ATTR_INIT(RTPerson, unsigned,    sflags,       0);
       PLDAP_ATTR_INIT(RTPerson, unsigned,    ssecurity,    0);
       PLDAP_ATTR_INIT(RTPerson, unsigned,    smodop,       0);
       PLDAP_ATTR_INIT(RTPerson, unsigned,    sttl,         3600);
       PLDAP_ATTR_SIMP(RTPerson, PStringList, sprotid);
       PLDAP_ATTR_SIMP(RTPerson, PStringList, sprotmimetype);
       PLDAP_ATTR_INIT(RTPerson, PString,     sappid,       PProcess::Current().GetName()); // Must be non-empty
       PLDAP_ATTR_INIT(RTPerson, PString,     sappguid,     "none"); // Must be non-empty
       PLDAP_ATTR_SIMP(RTPerson, PStringList, smimetype);
       PLDAP_ATTR_INIT(RTPerson, BOOL,        ilsa32833566, 0); // 1=audio capable
       PLDAP_ATTR_INIT(RTPerson, BOOL,        ilsa32964638, 0); // 1=video capable
       PLDAP_ATTR_INIT(RTPerson, BOOL,        ilsa26214430, 0); // 1=in a call
       PLDAP_ATTR_INIT(RTPerson, unsigned,    ilsa26279966, 0); // unknown
       PLDAP_ATTR_INIT(RTPerson, unsigned,    ilsa39321630, 0); // 1 personal; 2 business user; 4 adults-only
       PLDAP_ATTR_INIT(RTPerson, time_t,      timestamp,    PTime().GetTimeInSeconds());

      public:
       PString GetDN() const;

    PLDAP_STRUCT_END();

    BOOL AddPerson(
      const RTPerson & person
    );

    BOOL ModifyPerson(
      const RTPerson & person
    );

    BOOL DeletePerson(
      const RTPerson & person
    );

    BOOL SearchPerson(
      const PString & canonicalName,
      RTPerson & person
    );

    PList<RTPerson> SearchPeople(
      const PString & filter
    );
};

#endif // P_LDAP

#endif // _PILS_H


// End of file ////////////////////////////////////////////////////////////////
