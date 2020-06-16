
/*
 * h350.h
 *
 * H.350 LDAP interface class.
 *
 * h323plus library
 *
 * Copyright (c) 2007 ISVO (Asia) Pte. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the General Public License (the  "GNU License"), in which case the
 * provisions of GNU License are applicable instead of those
 * above. If you wish to allow use of your version of this file only
 * under the terms of the GNU License and not to allow others to use
 * your version of this file under the MPL, indicate your decision by
 * deleting the provisions above and replace them with the notice and
 * other provisions required by the GNU License. If you do not delete
 * the provisions above, a recipient may use your version of this file
 * under either the MPL or the GNU License."
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 *
 * The Initial Developer of the Original Code is ISVO (Asia) Pte. Ltd.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: h350.h,v $
 * Revision 1.1.1.1  2020/01/20 06:08:40  bishnu
 * conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
 * It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
 * CDOT-MCU works as service provider (roomNo@serviceIP:Port)
 * room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.
 *
 * For more Details go through the 'conferncing_Overview-mod' document
 *
 * Revision 1.1.1.1  2020/01/14 11:23:52  root
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
 * Revision 1.5  2008/01/05 12:05:53  shorne
 * small code tidy up
 *
 * Revision 1.4  2008/01/05 11:36:01  shorne
 * More Fixes for Linux
 *
 * Revision 1.3  2008/01/02 19:28:02  shorne
 * Removed duplicate link to plugin factory
 *
 * Revision 1.2  2008/01/02 18:57:56  willamowius
 * compile fix for macro concatenation with gcc
 *
 * Revision 1.1  2007/08/06 20:50:50  shorne
 * First commit of h323plus
 *
 *
 *
 */

#pragma once

#ifdef H323_H350

#ifndef _H323_H350
#define _H323_H350

#include <map>
#include <list>

#define P_FORCE_STATIC_PLUGIN

class H350_Session   : public PLDAPSession
{
  public:
     typedef std::list<PLDAPSchema> LDAP_Record;
     typedef std::map<PString,LDAP_Record> LDAP_RecordList;

	 BOOL Open(const PString & hostname, WORD port = 389);

	 BOOL Login(const PString & who, const PString & passwd, PLDAPSession::AuthenticationMethod authMethod=AuthSimple);

	 void NewRecord(LDAP_Record & rec);

	 BOOL SetAttribute(LDAP_Record & record,const PString & attrib, const PString & value);
     BOOL SetAttribute(LDAP_Record & record,const PString & attrib, const PBYTEArray & value);

 	 BOOL GetAttribute(LDAP_Record & record,const PString & attrib, PString & value);
	 BOOL GetAttribute(LDAP_Record & record,const PString & attrib, PBYTEArray & value);

	 BOOL PostNew(const PString & dn, const LDAP_Record & record);
	 BOOL PostUpdate(const PString & dn, const LDAP_Record & record);

	 BOOL Delete() { return FALSE; }

	 int Search(const PString & base, 
		         const PString & filter, 
				 LDAP_RecordList & results,
				 const PStringArray & attributes = PStringList()
				 );
};

#define H350_Schema(cname)  \
class cname##_schema  : public PLDAPSchema \
{   \
  public: static PStringList SchemaName() { return PStringList(cname##_SchemaName); } \
  void AttributeList(attributeList & attrib) { \
   for (PINDEX i = 0; i< PARRAYSIZE(cname##_attributes ); i++) \
	 attrib.push_back(Attribute(cname##_attributes[i].name,(AttributeType)cname##_attributes[i].type)); }; \
}; \
LDAP_Schema(cname); 

#endif // _H323_H350

#endif  

