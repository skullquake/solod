CC=gcc
CXX=g++
AR=ar
LN=ln
RM=ln
#-------------------------------------------------------------------------------
OS=$(shell $(CXX) -dumpmachine)
ifneq (,$(findstring mingw,$(OS)))
SOEXT?=.dll
BINEXT?=.exe
else
SOEXT?=.so
BINEXT?=
endif
ifeq ($(PREFIX),)
PREFIX := /usr/local
endif
#-------------------------------------------------------------------------------
#LIBS
#-------------------------------------------------------------------------------
LIBDIR=./lib
LIBDIRS=$(shell ls -d $(LIBDIR)/*/)
#-------------------------------------------------------------------------------
#APPLICATION
#-------------------------------------------------------------------------------
APPBUILDDIR=./bin/app
APPBIN=./bin/a$(BINEXT)
APPSRCDIR=src
APPSRC:=$(shell find $(APPSRCDIR) -name '*.cpp' -o  -name '*.c')
APPOBJS=$(addprefix $(APPBUILDDIR)/,$(patsubst %.c,%.o ,$(patsubst %.cpp,%.o,$(APPSRC))))
APPRPATH=./lib
APPCFLAGS=\
	-I./include\
	-I./include/shape\
	-L$(LIBDIR)\
	-DSOEXT=\"$(SOEXT)\"
APPLDFLAGS=\
	-ldl
#-------------------------------------------------------------------------------
#RULES
#-------------------------------------------------------------------------------
all:\
	libs\
	$(APPBIN)
#-------------------------------------------------------------------------------
#APPLICATION RULES
#-------------------------------------------------------------------------------
$(APPBIN):$(APPOBJS)
	$(CXX)\
		$(APPCFLAGS)\
		$(APPOBJS)\
		-o $(APPBIN)\
		$(APPLDFLAGS)\
		-Wl,-rpath=$(APPRPATH)
$(APPBUILDDIR)/%.o: %.cpp
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	$(CXX)\
		$(APPCFLAGS)\
		-c $<\
		$(APPLDFLAGS)\
		-o $@
$(APPBUILDDIR)/%.o: %.c
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	$(CC)\
		$(APPCFLAGS)\
		-c $<\
		$(APPLDFLAGS)\
		-o $@
#-------------------------------------------------------------------------------
#MISC
#-------------------------------------------------------------------------------
.phony:\
	libs\
	cleanlibs\
	run\
	clean\
	lsvar\
	nm\
	objdump	
libs:
	for d in $(LIBDIRS);\
	do\
		$(MAKE) --directory=$$d;\
	done
cleanlibs:
	for d in $(LIBDIRS);\
	do\
		$(MAKE) clean --directory=$$d;\
	done
nm:
	@printf "symbols:\n"
	nm -CD ./lib/liba.so
objdump:
	@printf "objdump:\n"
	objdump -t ./lib/liba.so
clean:
	@rm -r ./bin
	make cleanlibs
run: $(APPBIN)
	$(APPBIN)
lsvar:
	@echo $(LIBDIR)
	@echo $(LIBS)




