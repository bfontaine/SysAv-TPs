# Baptiste Fontaine & Julien Sagot -- TP 3

CC=gcc
CFLAGS=-std=gnu99 -Werror -Wall -Wextra -Wundef -Wpointer-arith -g

RM=rm -f
LIBTOOL=ar -q

MODULES=ex1
SRC=$(addsuffix .c,$(MODULES))
OBJS=$(addsuffix .o,$(MODULES))

DEPS=.deps

EXE=tp

CPPCHECK_VER:=$(shell cppcheck --version 2>/dev/null)
ifdef CPPCHECK_VER
CPPCHECK=cppcheck \
	--enable=warning,style \
	--language=c -q
else
# don't fail if it doesn't exist
CPPCHECK=\#
endif

.PHONY: all clean check

all: .deps $(EXE)

$(EXE): main.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(EXE)
	$(RM) *.o *~ .deps

check:
	$(CPPCHECK) $(SRC)

$(DEPS):
	gcc -M $(SRC) >| $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

-include .deps
