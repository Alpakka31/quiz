# Copyright (c) 2020, Patrik Nyström
# All rights reserved.

# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

OBJS = quiz.o readinput.o
CC := clang
CFLAGS := -Wall -pedantic -Wformat=2 -Wno-unused-parameter -Wshadow -Wwrite-strings -Wstrict-prototypes -Wold-style-definition -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -O2
PREFIX := /usr
BINDIR := ${PREFIX}/local/bin

.PHONY: all clean

quiz: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

quiz.o: quiz.c
	$(CC) $(CFLAGS) -c quiz.c

readinput.o: readinput/readinput.c
	$(CC) $(CFLAGS) -c readinput/readinput.c

install:
	install -Dm755 quiz $(DESTDIR)$(BINDIR)/quiz

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/quiz

clean:
	rm -f quiz $(OBJS)
