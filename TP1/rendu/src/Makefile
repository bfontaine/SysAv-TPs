# Baptiste Fontaine - Julien Sagot -- TP 1

CC=gcc
CFLAGS=-std=gnu99 -Werror -Wall -Wextra -Wundef -Wpointer-arith -g

RM=rm -f

MODULES=load_cpu load_ram
MANS=$(addsuffix .1,$(MODULES))
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

.PHONY: all clean check man

all: .deps $(EXES)

clean:
	$(RM) $(EXES)
	$(RM) *.o *~ .deps
	$(RM) -r *.dSYM

check:
	$(CPPCHECK) $(SRC)

man: $(MANS)

$(DEPS):
	gcc -M $(SRC) >| $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

%.1: %.md
	@# gem install ronn
	ronn -rw --manual "TP1 Manual" --pipe $< >| $@

%: %.o
	$(CC) $(CFLAGS) -o $@ $^

-include .deps
