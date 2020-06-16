#
# Makefile
#
# Make file for simple sample application for the xmpptest application in pwlib
#
# Copyright (c) 2006 Derek J Smithies
#
# The contents of this file are subject to the Mozilla Public License
# Version 1.0 (the "License"); you may not use this file except in
# compliance with the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
# the License for the specific language governing rights and limitations
# under the License.
#
# The Original Code is Open Phone Abstraction Library.
#
# The Initial Developer of the Original Code is Equivalence Pty. Ltd.
#
# Contributor(s): ______________________________________.
#
# $Log: Makefile,v $
# Revision 1.1.1.1  2020/01/20 06:08:44  bishnu
# conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
# It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
# CDOT-MCU works as service provider (roomNo@serviceIP:Port)
# room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.
#
# For more Details go through the 'conferncing_Overview-mod' document
#
# Revision 1.1.1.1  2020/01/14 11:23:53  root
# Final version of CDOT-MCU
#
# Revision 1.1.1.1  2020/01/14 08:43:29  root
# Final changes for the CDOT-MCU
#
# Revision 1.1.1.1  2019/12/19 09:12:34  root
#
# CDOT-MCU  conferencing module
#
#
# Revision 1.1  2006/07/23 03:39:49  dereksmithies
# Modify main.cxx so it compiles under linux.
# Add Makefile so it can be compiled under linux.
#
#
#

PROG		= xmpptest
SOURCES		:= \
	ConnectDialog.cxx \
	MainFrame.cxx     \
	main.cxx          \
	precompile.cxx    

#openphone.cxx : openphone.xrc
#	wxrc openphone.xrc -c -o openphone.cxx



STDCCFLAGS += `wx-config --cxxflags`

LDFLAGS += `wx-config  --libs`

include $(PTLIBDIR)/make/ptlib.mak


