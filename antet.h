#ifndef ANTET_H_INCLUDED
#define ANTET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> //int toupper(int c);

/**
    Antetul filei pentru file cu .c si .h
*/
void antet(char *fnc, char *fnh);
/**
    Create file README.md for github repository
*/
int readme(void);
/**
    Makefile create for run with utility Make
*/
int makefile(void);
/**
    Functia ruleaza programul din aceasta fila
*/
int run(void);

#endif // ANTET_H_INCLUDED
