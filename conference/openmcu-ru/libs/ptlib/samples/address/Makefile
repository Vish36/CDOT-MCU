# Simple makefile for the local address program.
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
# Revision 1.1  2005/03/10 09:19:00  dereksmithies
# Initial release of code to illustrate the reading of the machines external ip address and hostname
#
#
PROG    = local
SOURCES = local.cxx

ifndef PTLIBDIR
PTLIBDIR=$(HOME)/ptlib
endif

include $(PTLIBDIR)/make/ptlib.mak

# End of Makefile
