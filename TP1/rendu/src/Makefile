# Baptiste Fontaine - Julien Sagot -- TP 1

CC=gcc
CFLAGS=-std=gnu99 -Werror -Wall -Wextra -Wundef -Wpointer-arith -g

RM=rm -f

MODULES=load_cpu load_ram
SRC=$(addsuffix .c,$(MODULES))
OBJS=$(addsuffix .o,$(MODULES))

DEPS=.deps

EXES=$(MODULES)

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

all: .deps $(EXES)

clean:
	$(RM) $(EXE)
	$(RM) *.o *~ .deps

check:
	$(CPPCHECK) $(SRC)

$(DEPS):
	gcc -M $(SRC) >| $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

%: %.o
	$(CC) $(CFLAGS) -o $@ $^

-include .deps
