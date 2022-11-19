CC=pgcc#gcc
CFLAGS=-Mconcur -Minfo#-pg -Wno-incompatible-pointer-types
CPROF=pgprof
C_SOURCES=$(wildcard *.c)
C_OBJECTS=$(C_SOURCES:.c=.o)

BUILDDIR=build
PROFILES=profiles

help:
	@echo "! Run script using \"make all\" utilizing \"$(CC) $(CFLAGS)\""

all: dirs compile
dirs:
	mkdir -p $(BUILDDIR)
	mkdir -p $(PROFILES)
	mkdir -p log
compile: $(C_OBJECTS)
	@echo "! Successfully compiled and executed script."
	@echo "! Note: Some scripts are deactivated due to SegFault. See @FIXME"
%.o: %.c
	@echo "! Compiling source: $<"
	$(CC) $(CFLAGS) $< -o $(BUILDDIR)/$@
	$(BUILDDIR)/$@
	$(CPROF) $(BUILDDIR)/$@ > $(PROFILES)/$@_$(CPROF).log

clean:
	rm -f *.o *.out
	rm -f log/*
	rm -f build/*
	rm -f profiles/*