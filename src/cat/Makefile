SHELL := /bin/bash
CC = gcc
FLAG =-Wall -Wextra -Werror
FILE = bytes.txt
CHECK=2>&1 valgrind --tool=memcheck --leak-check=yes
SRCS = cat.c catFlags.c
BUELDER = ../../bueld/s21_cat

all: s21_cat tests clean

s21_cat:
	$(CC) $(FLAG) $(SRCS) -o $(BUELDER)

tests:
	-diff <($(BUELDER) $(FILE)) <(cat $(FILE))
	-diff <($(BUELDER) -e $(FILE)) <(cat -e $(FILE))
	-diff <($(BUELDER) -s $(FILE)) <(cat -s $(FILE))
	-diff <($(BUELDER) -b $(FILE)) <(cat -b $(FILE))
	-diff <($(BUELDER) -n $(FILE)) <(cat -n $(FILE))
	-diff <($(BUELDER) -etsnbv $(FILE)) <(cat -etsnbv $(FILE))
	-diff <($(BUELDER) -v $(FILE)) <(cat -v $(FILE))

clean :
	rm -rf $(OBJS)