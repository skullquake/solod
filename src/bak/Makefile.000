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
#LIBRARY[s]
#-------------------------------------------------------------------------------
LIBBUILDDIR=./bin/lib
LIBDIR=lib
LIBNAM=a
LIBPFX=lib
LIBVER=1
LIBBIN=$(LIBDIR)/$(LIBPFX)$(LIBNAM)$(SOEXT).$(LIBVER)
LIBLN=$(LIBDIR)/$(LIBPFX)$(LIBNAM)$(SOEXT)
LIBSRCDIR=src/lib
LIBSRC:=$(shell find $(LIBSRCDIR) -name "*.cpp" -o -name "*.c")
LIBOBJS=$(addprefix $(LIBBUILDDIR)/,$(patsubst %.c,%.o ,$(patsubst %.cpp,%.o,$(LIBSRC))))
LIBCFLAGS=\
	-I./include/lib
ifneq (,$(findstring mingw,$(OS)))
LIBLDFLAGS=\

else
LIBLDFLAGS=\
		-rdynamic 
endif

#-------------------------------------------------------------------------------
#APPLICATION
#-------------------------------------------------------------------------------
APPBUILDDIR=./bin/app
APPBIN=./bin/a$(BINEXT)
APPSRCDIR=src/app
#APPSRC:=$(shell find $(APPSRCDIR) -name '*.cpp')
#APPOBJS:=$(addprefix $(APPBUILDDIR)/,$(APPSRC:%.cpp=%.o))
APPSRC:=$(shell find $(APPSRCDIR) -name '*.cpp' -o  -name '*.c')
APPOBJS=$(addprefix $(APPBUILDDIR)/,$(patsubst %.c,%.o ,$(patsubst %.cpp,%.o,$(APPSRC))))
APPRPATH=./lib
APPCFLAGS=\
	-I./include/app\
	-I./include/lib\
	-L$(LIBDIR)\
	-DSOEXT=\"$(SOEXT)\"
APPLDFLAGS=\
	   -ldl
#-------------------------------------------------------------------------------
#RULES
#-------------------------------------------------------------------------------
all:\
	$(APPBIN)\
	$(LIBLN)
#-------------------------------------------------------------------------------
#APPLICATION RULES
#-------------------------------------------------------------------------------
$(APPBIN):$(APPOBJS)
	$(CXX)\
		$(APPCFLAGS)\
		$(APPOBJS)\
		-o $(APPBIN)\
		$(APPLDFLAGS)
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
#LIBRARY RULES
#-------------------------------------------------------------------------------
$(LIBLN):$(LIBBIN)
	$(LN)\
		-sfn \
		"$(shell pwd)/$(LIBBIN)" \
		"$(shell pwd)/$(LIBLN)"
$(LIBBIN):$(LIBOBJS)
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	@$(CXX)\
		$(LIBCFLAGS)\
		$(LIBOBJS)\
		$(LIBLDFLAGS)\
		-shared \
		-Wl,-soname,lib$(LIBNAM)$(SOEXT) \
		-o $(LIBBIN)
$(LIBBUILDDIR)/%.o: %.cpp
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	$(CXX)\
		$(LIBCFLAGS)\
		-c $<\
		-fPIC \
		$(LIBLDFLAGS)\
		-o $@
$(LIBBUILDDIR)/%.o: %.c
	@printf "generating $@...\n"
	@mkdir -p $(@D)
	$(CC)\
		$(LIBCFLAGS)\
		-c $<\
		-fPIC \
		-rdynamic \
		$(LIBLDFLAGS)\
		-o $@

#-------------------------------------------------------------------------------
#MISC
#-------------------------------------------------------------------------------
.phony:\
	run\
	clean\
	lsvar\
	nm\
	objdump	
nm:
	@printf "symbols:\n"
	nm -CD ./lib/liba.so
objdump:
	@printf "objdump:\n"
	objdump -t ./lib/liba.so
clean:
	@rm -r ./bin ./lib
run:
	$(APPBIN)
lsvar:
	@echo $(LIBSVERPTH)




