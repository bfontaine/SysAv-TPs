# Baptiste Fontaine -- TP 1

CC=gcc
CFLAGS=-std=gnu99 -Werror -Wall -Wextra -Wundef -Wpointer-arith -g

RM=rm -f
LIBTOOL=ar -q

MODULES=main cpu
SRC=$(addsuffix .c,$(MODULES))
OBJS=$(addsuffix .o,$(MODULES))

DEPS=.deps

EXE=tp1

CPPCHECK_VER:=$(shell cppcheck --version 2>/dev/null)
ifdef CPPCHECK_VER
CPPCHECK=cppcheck \
	--enable=warning,style \
	--language=c -q
else
# don't fail if it doesn't exist
CPPCHECK=\#
endif

.PHONY: all clean tests

all: .deps $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(LIBTARGETS) $(EXE) $(LIBTESTS)
	$(RM) *.o *~

check:
	$(CPPCHECK) $(SRC)

$(DEPS):
	gcc -M $(SRC) >| $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

-include .deps
