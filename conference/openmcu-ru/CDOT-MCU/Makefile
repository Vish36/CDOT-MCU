#
# Makefile
#

PREFIX          = /opt
OSTYPE          = linux
UNAME          := $(shell uname)
MACHTYPE	= x86_64
PROG		= openmcu-ru
SOURCES	       := main.cxx video.cxx conference.cxx filemembers.cxx custom.cxx h323.cxx html.cxx mcu.cxx sip.cxx template.cxx \
                   utils.cxx utils_av.cxx utils_list.cxx utils_type.cxx utils_json.cxx yuv.cxx \
                   mcu_rtp.cxx mcu_rtp_cache.cxx mcu_rtp_secure.cxx \
                   sockets.cxx telnet.cxx \
                   reg.cxx reg_sip.cxx reg_h323.cxx rtsp.cxx recorder.cxx mcu_caps.cxx mcu_codecs.cxx

CXX		= g++
CFLAGS         += -g -O2 
LDFLAGS        += -L../libs/srtp -L/home/cdot/vishnu/openmcu/build/openmcu-ru/libs/h323plus/lib -L/home/cdot/vishnu/openmcu/build/openmcu-ru/libs/ptlib/lib -L/opt/openmcu-ru/lib -L/usr/lib -L/usr/local/lib
RFLAGS         += -Wl,-R/opt/openmcu-ru/lib
SFLAGS         += 
SFLAGS_STATIC  +=  -Wl,--start-group /home/cdot/vishnu/openmcu/build/openmcu-ru/libs/ptlib/lib/libpt_linux_x86_64_r_s.a /home/cdot/vishnu/openmcu/build/openmcu-ru/libs/h323plus/lib/libh323_linux_x86_64_r_s.a -Wl,--end-group
SFLAGS_DEBUG   +=  -Wl,--start-group /home/cdot/vishnu/openmcu/build/openmcu-ru/libs/ptlib/lib/libpt_linux_x86_64_d_s.a /home/cdot/vishnu/openmcu/build/openmcu-ru/libs/h323plus/lib/libh323_linux_x86_64_d_s.a -Wl,--end-group
LDLIBS	       +=   -lsofia-sip-ua -lavcodec -lavutil -lavformat -lswscale -lswresample -lfreetype -lyuv -lssl -lsrtp -lh323_linux_x86_64_r -lpt_linux_x86_64_r
LDLIBS_STATIC  +=   -lsofia-sip-ua -lavcodec -lavutil -lavformat -lswscale -lswresample -lfreetype -lyuv -lssl -lsrtp
LDLIBS_DEBUG   +=   -lsofia-sip-ua -lavcodec -lavutil -lavformat -lswscale -lswresample -lfreetype -lyuv -lssl -lsrtp
STDCCFLAGS     +=  -D__STDC_CONSTANT_MACROS -Wall
STDCXXFLAGS    += 
CPPFLAGS       += -I../libs/h323plus/include -I../libs/ptlib/include -I../libs/srtp/crypto/include -I../libs/srtp/include -I/opt/openmcu-ru/include -I/opt/openmcu-ru/include/sofia-sip-1.12 -I/usr/include -I/usr/include/freetype2 -I/usr/local/include
OPTCCFLAGS      =$(CPPFLAGS)

git_revision        = $(shell git rev-list HEAD --max-count=1)
#git_revision_number = $(shell git rev-list HEAD | wc -l)
STDCCFLAGS     +=-D GIT_REVISION=$(git_revision)

PTLIBDIR        = /home/cdot/vishnu/openmcu/build/openmcu-ru/libs/ptlib
include $(PTLIBDIR)/make/ptbuildopts.mak

INSTALL = install
INSTALL_BACKUP_OPTS =
ifeq ($(UNAME), Linux)
  INSTALL = install
  INSTALL_BACKUP_OPTS = --compare --backup=numbered
endif
ifeq ($(UNAME), FreeBSD)
ifeq (, $(shell which ginstall))
  INSTALL = install
  INSTALL_BACKUP_OPTS = -C -b
else
  INSTALL = ginstall
  INSTALL_BACKUP_OPTS = --compare --backup=numbered
endif
endif


OBJDIR	= ./obj
OBJECTS = $(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(patsubst %.cxx,%.o,$(notdir $(SOURCES)))))

$(OBJDIR)/%.o : %.cxx
	@mkdir -p $(OBJDIR) >/dev/null 2>&1
	@echo [CC] $@
	@$(CXX) $(STDCCFLAGS) $(OPTCCFLAGS) $(CFLAGS) $(STDCXXFLAGS) -c $< -o $@

all: $(OBJECTS)
	$(CXX) $(LDSO) -o $(OBJDIR)/$(PROG) $^ $(CFLAGS) $(LDFLAGS) $(SFLAGS) $(RFLAGS) $(OBJS) $(LDLIBS) $(ENDLDLIBS) $(ENDLDFLAGS)

static: $(OBJECTS)
	$(CXX) $(LDSO) -o $(OBJDIR)/$(PROG) $^ $(CFLAGS) $(LDFLAGS) $(SFLAGS_STATIC) $(RFLAGS) $(OBJS) $(LDLIBS_STATIC) $(ENDLDLIBS) $(ENDLDFLAGS)

debug: $(OBJECTS)
	$(CXX) $(LDSO) -o $(OBJDIR)/$(PROG) $^ $(CFLAGS) $(LDFLAGS) $(SFLAGS_DEBUG) $(RFLAGS) $(OBJS) $(LDLIBS_DEBUG) $(ENDLDLIBS) $(ENDLDFLAGS)


install:
	mkdir -p $(DESTDIR)/opt/openmcu-ru
	mkdir -p $(DESTDIR)/opt/openmcu-ru/bin
	mkdir -p $(DESTDIR)/opt/openmcu-ru/config
	mkdir -p $(DESTDIR)/opt/openmcu-ru/font
	mkdir -p $(DESTDIR)/opt/openmcu-ru/lib
	mkdir -p $(DESTDIR)/opt/openmcu-ru/log
	mkdir -p $(DESTDIR)/opt/openmcu-ru/pipe
	mkdir -p $(DESTDIR)/opt/openmcu-ru/records
	mkdir -p $(DESTDIR)/opt/openmcu-ru/resource
	mkdir -p $(DESTDIR)/opt/openmcu-ru/ssl
	mkdir -p $(DESTDIR)/opt/openmcu-ru/scripts
	( for file in ./files/conf/*; do \
	    $(INSTALL) -m 644 $(INSTALL_BACKUP_OPTS) $$file $(DESTDIR)/opt/openmcu-ru/config; \
	done )
	( for file in ./files/font/*; do \
	    $(INSTALL) -m 644 $$file $(DESTDIR)/opt/openmcu-ru/font; \
	done )
	( for file in ./files/resource/*; do \
	    $(INSTALL) -m 644 $$file $(DESTDIR)/opt/openmcu-ru/resource; \
	done )
	( for file in ./files/scripts/*; do \
	    $(INSTALL) -m 755 $(INSTALL_BACKUP_OPTS) $$file $(DESTDIR)/opt/openmcu-ru/scripts; \
	done )
	$(INSTALL) -m 755 $(OBJDIR)/$(PROG) $(DESTDIR)/opt/openmcu-ru/bin
#	ln -sf $(DESTDIR)/opt/openmcu-ru/bin/$(PROG) /usr/local/bin/$(PROG)
	$(INSTALL) -m 644 ../AUTHORS $(DESTDIR)/opt/openmcu-ru
	$(INSTALL) -m 644 ../COPYING $(DESTDIR)/opt/openmcu-ru
	$(INSTALL) -m 644 ../NEWS $(DESTDIR)/opt/openmcu-ru
	$(INSTALL) -m 644 ../README $(DESTDIR)/opt/openmcu-ru

uninstall:
	rm -rf $(DESTDIR)/opt/openmcu-ru/font
	rm -rf $(DESTDIR)/opt/openmcu-ru/log
	rm -rf $(DESTDIR)/opt/openmcu-ru/pipe
	rm -rf $(DESTDIR)/opt/openmcu-ru/resource
	rm -rf $(DESTDIR)/opt/openmcu-ru/scripts
	rm -f $(DESTDIR)/opt/openmcu-ru/AUTHORS
	rm -f $(DESTDIR)/opt/openmcu-ru/COPYING
	rm -f $(DESTDIR)/opt/openmcu-ru/NEWS
	rm -f $(DESTDIR)/opt/openmcu-ru/README
	rm -f $(DESTDIR)/opt/openmcu-ru/bin/$(PROG)
#	rm -f /usr/local/bin/$(PROG)

clean:
	rm -rf $(OBJDIR)
