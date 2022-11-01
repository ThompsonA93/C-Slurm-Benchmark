.SUFFIXES: .c

ELEMENTS=10000 20000 30000 40000

CC=gcc
CFLAGS=-pg
C_SOURCES=$(wildcard *.c)
C_OBJECTS=$(C_SOURCES:.c=.o)

BUILDDIR=build
PROFILES=profiles

help:
	@echo "! Run script using \"make all ELEMENTS=50000\""
	@echo "! Run script using \"make bubble_sort\""

all: dirs compile

dirs:
	mkdir -p $(BUILDDIR)
	mkdir -p $(PROFILES)
	mkdir -p log

compile: $(C_OBJECTS)
	@echo "! Successfully compiled and executed script."

# FIXME: Foreach does not iterate correctly for some reason
%.o: %.c
	@echo "! Compiling source: $<"
	$(foreach var, $(ELEMENTS), \
		$(CC) $(CFLAGS) -D MAX_ARRAY_ELEMENTS=$(var) $< -o $(BUILDDIR)/$@; \
		$(BUILDDIR)/$@; \
		gprof $(BUILDDIR)/$@ gmon.out > $(PROFILES)/$@_gmon.log \
	)

clean:
	rm -f *.o *.out
	rm -f build/*
	rm -f profiles/*
	rm -f log/*