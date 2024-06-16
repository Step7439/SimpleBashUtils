#include "cat.h"

static const char OPTIONS[] = "beEvnstT";

struct option longOption[] = {{"nomber-nonblank", 0, NULL, 'b'},
                              {"number", 0, NULL, 'n'},
                              {"squeeze", 0, NULL, 's'},
                              {NULL, 0, NULL, 0}};

void catStart(Flags *const flags, int argc, char *const argv[]) {
  int correntFlag = getopt_long(argc, argv, OPTIONS, longOption, 0);

  while (correntFlag != END) {
    options_set(flags, correntFlag);
    correntFlag = getopt_long(argc, argv, OPTIONS, longOption, 0);
  }
  if (flags->b) {
    flags->n = false;
  }
}

void options_set(Flags *const flags, const char correntFlag) {
  switch (correntFlag) {
    case 'b':
      flags->b = true;
      break;
    case 'v':
      flags->v = true;
      break;
    case 'e':
      flags->v = true;
      flags->e = true;
      break;
    case 'E':
      flags->e = true;
      break;
    case 'n':
      flags->n = true;
      break;
    case 's':
      flags->s = true;
      break;
    case 't':
      flags->v = true;
      flags->t = true;
      break;
    case 'T':
      flags->t = true;
      break;
  }
}

void outCat(FILE *file, Flags flagse, const char *table[static 256]) {
  int c = 0;
  int last = '\n';
  bool last2 = false;
 // char last3 = '\0';
  int len = 0;
  (void)flagse;
  while (fread(&c, 1, 1, file) > 0) {
    if (last == '\n') {
      if (flagse.s && c == '\n') {
        if (last2) continue;
        last2 = true;
      } else
        last2 = false;

      if (flagse.b) {
        if (c != '\n') printf("%6i\t", ++len);
      } else if (flagse.n) {
        printf("%6i\t", ++len);
      }
    }
    if (!*table[c])
      printf("%c", '\0');
    else
      printf("%s", table[c]);
    last = c;
  }
}
void catFile(int argc, char *argv[], Flags flags,
             const char *table[static 256]) {
  for (char **filename = &argv[1], **end = &argv[argc]; filename != end;
       ++filename) {
    if (**filename == '-') continue;
    FILE *file = fopen(*filename, "rb");
    if (errno) {
      fprintf(stderr, "%s", argv[0]);
      perror(*filename);
      continue;
    }
    outCat(file, flags, table);
    fclose(file);
  }
}

int main(int argc, char *argv[]) {
  Flags flags = {false};
  catStart(&flags, argc, argv);
  const char *table[256];
  catTable(table);

  if (flags.e) {
    catTableEndl(table);
  }
  if (flags.t) {
    catTableTab(table);
  }
  if (flags.v) {
    catTableNonPrinteble(table);
  }

  catFile(argc, argv, flags, table);
}
