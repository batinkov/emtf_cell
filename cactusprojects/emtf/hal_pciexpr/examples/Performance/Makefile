#                         -*-Makefile-*-
# $Id: Makefile,v 1.2 2007/04/10 08:05:54 cschwick Exp $

PWD=$(shell pwd)

ifndef XDAQ_ROOT
STANDALONE=1
export STANDALONE
XDAQ_ROOT=$(PWD)/../..
BUILD_HOME=$(PWD)/../..
include $(PWD)/../../Makefile.in
endif


include $(XDAQ_ROOT)/config/mfAutoconf.rules
include $(XDAQ_ROOT)/config/mfDefs.coretools
include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)

.PHONY:runnit.sh
runnit.sh : _all
	echo > runnit.sh "#!/bin/sh"
	echo >> runnit.sh "export LD_LIBRARY_PATH=$(PWD)/../../$(XDAQ_PLATFORM)/lib:$(XDAQ_ROOT)/lib:$(XERCESDIR)/lib"
	echo >> runnit.sh 'echo $$LD_LIBRARY_PATH'
	echo >> runnit.sh "bin/$(XDAQ_OS)/$(XDAQ_PLATFORM)/PerformanceTester.exe"
	chmod +x runnit.sh

Project=daq/hal
Package=examples/Performance
ifdef STANDALONE
Project = .
endif

Sources =

DynamicLibrary=
StaticLibrary=

IncludeDirs = \
        $(BUILD_HOME)/$(Project)/$(XDAQ_PLATFORM)/include \
        $(BUILD_HOME)/$(Project)/$(XDAQ_PLATFORM)/include/$(XDAQ_OS) \
        $(XDAQ_ROOT)/include

LibraryDirs = $(BUILD_HOME)/$(Project)/$(XDAQ_PLATFORM)/lib \
              $(XDAQ_ROOT)/lib
Libraries = xcept toolbox asyncresolv log4cplus uuid GenericHAL DummyBusAdapters

ifndef STANDALONE
Libraries += config xerces-c
IncludeDIrs += $(XCEPT_INCLUDE_PREFIX)
endif

# implies STANDALONE
ifdef XERCESDIR
   IncludeDirs += $(XERCESDIR)/include
   LibraryDirs += $(XERCESDIR)/lib
   Libraries   += xerces-c
endif

DependentLibraryDirs = 
DependentLibraries = 

UserCFlags =
UserCCFlags = 
UserDynamicLinkFlags =
UserStaticLinkFlags =
UserExecutableLinkFlags =

# These libraries can be platform specific and
# potentially need conditional processing

ExternalObjects =

# Compile the source files and create a shared library

Executables=PerformanceTester.cc

# Local Makefile.rules is a copy of TriDAS/config/Makefile.rules plus a
# modification to use the Libraries tag when building a shared library
include $(XDAQ_ROOT)/config/Makefile.rules

