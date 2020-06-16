/*
 * pxmlrpcs.h
 *
 * XML parser support
 *
 * Portable Windows Library
 *
 * Copyright (c) 2002 Equivalence Pty. Ltd.
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
 * $Log: pxmlrpcs.h,v $
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
 * Revision 1.4  2005/11/30 12:47:37  csoutheren
 * Removed tabs, reformatted some code, and changed tags for Doxygen
 *
 * Revision 1.3  2003/02/19 01:50:31  robertj
 * Change to make it easier to set a fault from the server function handler.
 *
 * Revision 1.2  2002/11/06 22:47:24  robertj
 * Fixed header comment (copyright etc)
 *
 * Revision 1.1  2002/10/02 08:54:34  craigs
 * Added support for XMLRPC server
 *
 */

#ifndef _PXMLRPCSRVR_H
#define _PXMLRPCSRVR_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <ptclib/pxmlrpc.h>
#include <ptclib/http.h>


class PXMLRPCServerMethod : public PString
{
  PCLASSINFO(PXMLRPCServerMethod, PString);
  public:
    PXMLRPCServerMethod(const PString & name)
      : PString(name) { }

    PNotifier methodFunc;
};


PSORTED_LIST(PXMLRPCServerMethodList, PXMLRPCServerMethod);


class PXMLRPCServerResource : public PHTTPResource
{
  PCLASSINFO(PXMLRPCServerResource, PHTTPResource);
  public:
    PXMLRPCServerResource();
    PXMLRPCServerResource(
      const PHTTPAuthority & auth    ///< Authorisation for the resource.
    );
    PXMLRPCServerResource(
      const PURL & url               ///< Name of the resource in URL space.
    );
    PXMLRPCServerResource(
      const PURL & url,              ///< Name of the resource in URL space.
      const PHTTPAuthority & auth    ///< Authorisation for the resource.
    );

    // overrides from PHTTPResource
    BOOL LoadHeaders(PHTTPRequest & request);
    BOOL OnPOSTData(PHTTPRequest & request, const PStringToString & data);

    // new functions
    virtual void OnXMLRPCRequest(const PString & body, PString & reply);
    virtual BOOL SetMethod(const PString & methodName, const PNotifier & func);
    void OnXMLRPCRequest(const PString & methodName, PXMLRPCBlock & request, PString & reply);

    virtual PString FormatFault(
      PINDEX code,
      const PString & str
    );

  protected:
    PMutex methodMutex;
    PXMLRPCServerMethodList methodList;
};


class PXMLRPCServerParms : public PObject 
{
  PCLASSINFO(PXMLRPCServerParms, PObject);
  public:
    PXMLRPCServerParms(
      PXMLRPCServerResource & _resource,
      PXMLRPCBlock & _request
    ) : resource(_resource), request(_request) { }

    void SetFault(
      PINDEX code,
      const PString & text
    ) { request.SetFault(code, resource.FormatFault(code, text)); }

    PXMLRPCServerResource & resource;
    PXMLRPCBlock & request;
    PXMLRPCBlock response;
};


#endif


