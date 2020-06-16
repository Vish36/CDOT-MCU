/*
 * sasl.h
 *
 * Simple Authentication Security Layer interface classes
 *
 * Portable Windows Library
 *
 * Copyright (c) 2004 Reitek S.p.A.
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
 * The Initial Developer of the Original Code is Post Increment
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: psasl.h,v $
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
 * Revision 1.3  2004/11/11 07:34:50  csoutheren
 * Added #include <ptlib.h>
 *
 * Revision 1.2  2004/04/28 11:26:42  csoutheren
 * Hopefully fixed SASL and SASL2 problems
 *
 * Revision 1.1  2004/04/18 12:02:31  csoutheren
 * Added classes for SASL authentication
 * Thanks to Federico Pinna and Reitek S.p.A.
 *
 *
 */

#if P_SASL2
#ifndef _PSASL
#define _PSASL

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <ptlib.h>

class PSASLClient : public PObject
{
    PCLASSINFO(PSASLClient, PObject);

public:
    enum  PSASLResult {
        Continue = 1,
        OK = 0,
        Fail = -1
    };

protected:
    static PString  s_Realm;
    static PString  s_Path;

    void *          m_CallBacks;
    void *          m_ConnState;
    const PString   m_Service;
    const PString   m_UserID;
    const PString   m_AuthID;
    const PString   m_Password;

    BOOL            Start(const PString& mechanism, const char ** output, unsigned& len);
    PSASLResult     Negotiate(const char * input, const char ** output);

public:
    PSASLClient(const PString& service, const PString& uid, const PString& auth, const PString& pwd);
    ~PSASLClient();

    static void     SetRealm(const PString& realm)  { s_Realm = realm; }
    static void     SetPath(const PString& path)    { s_Path = path; }

    static const PString&  GetRealm()               { return s_Realm; }
    static const PString&  GetPath()                { return s_Path; }

    const PString&  GetService() const  { return m_Service; }
    const PString&  GetUserID() const   { return m_UserID; }
    const PString&  GetAuthID() const   { return m_AuthID; }
    const PString&  GetPassword() const { return m_Password; }

    BOOL            Init(const PString& fqdn, PStringSet& supportedMechanisms);
    BOOL            Start(const PString& mechanism, PString& output);
    PSASLResult     Negotiate(const PString& input, PString& output);
    BOOL            End();
};

#endif  // _PSASL
#endif  // P_SASL2

// End of File ///////////////////////////////////////////////////////////////
