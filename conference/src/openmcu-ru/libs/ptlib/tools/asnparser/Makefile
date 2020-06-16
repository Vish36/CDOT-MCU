#
# Makefile
#
# Make file for ASN parser
#
# Portable Windows Library
#
# Copyright (c) 1998-2000 Equivalence Pty. Ltd.
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
# The Original Code is Portable Windows Library.
#
# The Initial Developer of the Original Code is Equivalence Pty. Ltd.
#
# Portions are Copyright (C) 1993 Free Software Foundation, Inc.
# All Rights Reserved.
# 
# Contributor(s): ______________________________________.
#
# $Log: Makefile,v $
# Revision 1.1.1.1  2020/01/20 06:09:04  bishnu
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
# Revision 1.1.1.1  2020/01/14 08:43:31  root
# Final changes for the CDOT-MCU
#
# Revision 1.1.1.1  2019/12/19 09:12:34  root
#
# CDOT-MCU  conferencing module
#
#
# Revision 1.12  2004/06/01 07:32:46  csoutheren
# Removed warning on Linux
#
# Revision 1.11  2003/07/28 18:29:41  dsandras
# Patch to help with make -jN thanks to Alexander Larsson <alexl@redhat.com>.
#
# Revision 1.10  2002/01/27 00:07:10  craigs
# Added rule to create asnparser.txt file
#
# Revision 1.9  2000/04/26 01:03:46  robertj
# Removed tarfile creation target, this is done differently now.
#
# Revision 1.8  2000/04/06 20:18:57  craigs
# Removed local install target
#
# Revision 1.7  2000/01/22 22:39:58  robertj
# Added missing license and log messages comment.
#


ifndef PTLIBDIR
PTLIBDIR=$(HOME)/ptlib
endif

PROG		= asnparser
SOURCES		= asn_grammar.cxx asn_lex.cxx main.cxx

CLEAN_FILES	= asn_grammar.cxx asn_grammar.h asn_grammar.output asn_lex.cxx asnparser.txt


include $(PTLIBDIR)/make/ptlib.mak

asn_grammar.cxx: asn_grammar.y
	@if [ ! -d $(OBJDIR) ] ; then mkdir $(OBJDIR) ; fi
	bison -t -v -d -o $* $<
	mv $* $*.cxx

main.cxx: asn_grammar.cxx

asn_lex.cxx: asn_lex.l
	flex -t $< > $@

asnparser.txt:	asnparser.1
		nroff -man $< | col -b > $@

test:
	./obj_linux_x86_d/asnparser -s2 -m H225 -r MULTIMEDIA-SYSTEM-CONTROL=H245 -c h225.asn

