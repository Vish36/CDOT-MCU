#
# ptlib.mak
#
# mak rules to be included in a ptlib application Makefile.
#
# Portable Windows Library
#
# Copyright (c) 1993-1998 Equivalence Pty. Ltd.
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
# $Log: ptlib.mak,v $
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
# Revision 1.5  2005/08/14 13:12:42  csoutheren
# Fixed misleading error message from make when PWLIBDIR not defined
#
# Revision 1.4  2005/02/23 21:29:52  dominance
# have configure check for bison as we know we'll need it and stop implicit definition of PWLIBDIR. *geesh* that was about time, eh? ;)
#
# Revision 1.3  1998/12/02 02:37:31  robertj
# New directory structure.
#
# Revision 1.2  1998/09/24 04:20:52  robertj
# Added open software license.
#

ifndef PTLIBDIR

ifdef PWLIBDIR
PTLIBDIR=$(PWLIBDIR)
else

$(error No PTLIBDIR environment variable defined! \
You need to define PTLIBDIR! \
Try something like: \
PTLIBDIR = $(HOME)/ptlib)

endif
endif

include $(PTLIBDIR)/make/unix.mak
include $(PTLIBDIR)/make/common.mak

# End of ptlib.mak
