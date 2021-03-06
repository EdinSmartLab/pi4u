SRC := 	engine_cmaes.c \
		cmaes.c \
		fitfun.c \
		surrogate.cpp \
		../priors/priors.c \
		../priors/myrand.c


ALL_SRC := $(SRC)
TARGETS := scma

OBJDIR = .o
TMP=$(subst ../,,$(SRC))
OBJ:= $(patsubst %,$(OBJDIR)/%.o,$(basename  $(TMP)))




#==============================================================================
#	COMPILERS AND FLAGS
#==============================================================================
use_torc?=0

CXX := g++
CC := gcc
LD := g++

ifeq ($(use_torc),1)
	CC = mpicc
	CXX = mpic++
	LD = mpic++
	CFLAGS += -D_USE_TORC_=1 `torc_cflags`
	LDLIBS += `torc_libs`
endif


CFLAGS += -O3 -std=c99
CFLAGS += -D_XOPEN_SOURCE=700 -D_BSD_SOURCE
CFLAGS += -Wall -Wno-unused-function
CFLAGS += `gsl-config --cflags`

CXXFLAGS += -O3
CXXFLAGS += -Wall
CXXFLAGS += `pkg-config libgp --cflags`


LDLIBS += `gsl-config --libs`
LDLIBS += `pkg-config libgp --libs`
LDLIBS += -lm -lpthread


COMPILE.c   = $(CC)  $(CFLAGS)   -c -o $@
COMPILE.cxx = $(CXX) $(CXXFLAGS) -c -o $@
LINK.o      = $(LD)  $(LDFLAGS)     -o $@


$(shell mkdir -p $(OBJDIR) )

#==============================================================================
#	RULES
#==============================================================================
all: $(TARGETS)


scma: $(OBJ)
	$(LINK.o) $^ $(LDLIBS)


$(OBJDIR)/%.o: %.c
	@mkdir -p "$(@D)"
	$(COMPILE.c) $<

$(OBJDIR)/%.o: %.cpp
	@mkdir -p "$(@D)"
	$(COMPILE.cxx) $<


$(OBJDIR)/priors/%.o: ../priors/%.c
	@mkdir -p "$(@D)"
	$(COMPILE.c) $<



ctags:
	@rm .tags .tags1 tags
	@ctags $(ALL_SRC)


print:


test: scma
	atest `find test -name main`

clean:
	rm -rf  $(TARGETS) $(OBJDIR)


clear:
	rm -rf .tags* tags *.txt *.dat actparcmaes.par *.err

.PHONY: clear clean print ctags test
