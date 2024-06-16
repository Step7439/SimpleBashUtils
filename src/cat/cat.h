#ifndef CAT
#define CAT
#include <stdbool.h>

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <unistd.h>

#define END -1

typedef struct Flags
{
    bool b;
    bool e;
    bool n;
    bool s;
    bool t;
    bool v;
} Flags;

void catStart(Flags *const flags, int argc, char *const argv[]);
void catFlags(int argc, char *argv[]);
void options_set(Flags* const flags, const char correntFlag);
void outCat(FILE *file, Flags flagse, const char *table[static 256]);
void catFile(int argc, char *argv[], Flags flags, const char *table[static 256]);
void catTable(const char *table[static 256]);
void catTableEndl(const char *table[static 256]);
void catTableTab(const char *table[static 256]);
void catTableNonPrinteble(const char *table[static 256]);

#endif