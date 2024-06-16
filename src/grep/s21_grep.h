#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <errno.h>
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

#define BSIZE 1000000

struct greph {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int sumStr;
  FILE *file;
} p;

void init();
int parser(int argc, char *argv[], char *phrase);
int phrase_file(char *phrase, char *buff);
void greph(char *phrase, char *fileName, char argc);
void edit_file(regex_t rgx, char *fileName, char argc);
void greph_logic(int argc, char *argv[], char *buff);
int options(char flag, char *phrase);

#endif  // SRC_GREP_S21_GREP_H_
