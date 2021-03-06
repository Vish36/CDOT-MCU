#
# Makefile for GSM 06.10
#
# Copyright (C) 2004 Post Increment, All Rights Reserved
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
# The Original Code is Open H323 library.
#
# The Initial Developer of the Original Code is Post Increment
#
# Contributor(s): ______________________________________.
#
# $Log: Makefile,v $
# Revision 1.1.1.1  2020/01/20 06:09:02  bishnu
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
# Revision 1.1  2007/10/22 07:41:25  shorne
# *** empty log message ***
#
# Revision 1.4  2007/04/19 06:09:04  csoutheren
# Fixed plugin build system to use better detection for OSX
# Resolved 1636262 - Fix for audio plugins for OSX
#
# Revision 1.3  2006/09/06 23:09:21  csoutheren
# Add Makefile and more implementation for Linux H.263
#
# Revision 1.3  2006/08/20 00:32:25  csoutheren
# Added missing files to Makefile
#
# Revision 1.2  2006/08/12 10:59:14  rjongbloed
# Added Linux build for H.261 plug-in.
#

PREFIX=/usr/local
exec_prefix = ${PREFIX}
LIBDIR=${exec_prefix}/lib

BASENAME= h263-ffmpeg
SONAME	=$(BASENAME)

CC	 	=gcc
CFLAGS	 	=-g -O2
CXX	 	=g++
LDSO	 	=-shared -Wl,-soname,$(SONAME)
PLUGINEXT	=so
STDCCFLAGS	=-fPIC
LDFLAGS		=

SRCS	+= h263ffmpeg.cxx

OBJDIR = ./obj

$(OBJDIR)/%.o : %.cxx
	@mkdir -p $(OBJDIR) >/dev/null 2>&1
	$(CC) -I../../../include $(EXTRACCFLAGS) $(STDCCFLAGS) $(OPTCCFLAGS) $(CFLAGS) -c $< -o $@

PLUGIN	= ./$(BASENAME)_video_pwplugin.$(PLUGINEXT)
STATIC	= ./lib$(BASENAME)_video_s.a

OBJECTS = $(addprefix $(OBJDIR)/,$(patsubst %.cxx,%.o,$(notdir $(SRCS))))

$(PLUGIN): $(OBJECTS)
	$(CXX) $(LDSO) -o $@ $^

install:
	mkdir -p $(DESTDIR)$(LIBDIR)/pwlib/codecs/video/
	cp $(PLUGIN) $(DESTDIR)$(LIBDIR)/pwlib/codecs/video/

uninstall:
	rm -f $(DESTDIR)$(LIBDIR)/pwlib/codecs/video/$(PLUGIN)

clean:
	rm -f $(OBJECTS) $(PLUGIN)

###########################################
