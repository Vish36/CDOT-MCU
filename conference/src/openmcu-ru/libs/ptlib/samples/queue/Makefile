#
# Makefile
#
# Make file for application to test the PQueueChannel class
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
# The Original Code is jester, jitter tester.
#
# The Initial Developer of the Original Code is Derek J Smithies
#
# Contributor(s): ______________________________________.
#
# $Log: Makefile,v $
# Revision 1.1.1.1  2020/01/20 06:09:07  bishnu
# conference is the CDOT-MCU (CDOT conferencing server or CDOT- multipoint control unit)
# It should be integrated with CDOT-ngms (in MAX-NG C5 or any other SIP PROXY, which can actually land the conferencing call on the CDOT-MCU)
# CDOT-MCU works as service provider (roomNo@serviceIP:Port)
# room number should be dialed from any point such as MAX-NG C5 or any proxy, because a SIP hardphone can not dial the full SIP-URI (roomNo@serviceIP:Port) hence there should be any intermediate entity.
#
# For more Details go through the 'conferncing_Overview-mod' document
#
# Revision 1.1.1.1  2020/01/14 11:23:54  root
# Final version of CDOT-MCU
#
# Revision 1.1.1.1  2020/01/14 08:43:31  root
# Final changes for the CDOT-MCU
#
# Revision 1.1.1.1  2019/12/19 09:12:34  root
#
# CDOT-MCU  conferencing module
#
#
# Revision 1.2  2006/12/07 20:49:39  dereksmithies
# Add doxygen comments to this program.
# Add doxygen configure file.
#
# Revision 1.1  2006/12/07 08:46:17  dereksmithies
# Initial cut of code to test the operation of PQueueChannel class.
#
#
#

PROG		= queue
SOURCES		:= main.cxx precompile.cxx



include $(PTLIBDIR)/make/ptlib.mak


docs: 
	doxygen docs.cfg

