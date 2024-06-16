SHELL := /bin/bash
CC = gcc
FLAG =-Wall -Wextra -Werror
FILE = pattern.txt
CHECK=2>&1 valgrind --tool=memcheck --leak-check=yes
SRCS = s21_grep.c
BUELDER = ../../bueld/s21_grep

all: s21_grep tests clean

s21_grep:
	$(CC) $(FLAG) $(SRCS) -o $(BUELDER)

tests:
	-diff <($(BUELDER) He $(FILE)) <(grep He $(FILE))
	-diff <($(BUELDER) -v He $(FILE)) <(grep -v He $(FILE))
	-diff <($(BUELDER) -iv He $(FILE)) <(grep -iv He $(FILE))
	-diff <($(BUELDER) -in He $(FILE)) <(grep -in He $(FILE))
	-diff <($(BUELDER) -ie "^he" $(FILE)) <(grep -ie "^he" $(FILE))
	#-diff <($(BUELDER) -ince "^he" $(FILE)) <(grep -ince "^he" $(FILE))
	-diff <($(BUELDER) -lh se $(FILE)) <(grep -lh se $(FILE))
	-diff <($(BUELDER) -hc e $(FILE)) <(grep -hc e $(FILE))

	-diff <($(BUELDER) -e He -e he $(FILE)) <(grep -e He -e he $(FILE))

clean :
	rm -rf $(OBJS)