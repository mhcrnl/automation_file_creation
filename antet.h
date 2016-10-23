#ifndef ANTET_H_INCLUDED
#define ANTET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> //int toupper(int c);

/**
   1. Antetul filei pentru file cu .c si .h
*/
void antet(char *fnc, char *fnh);
/**
   2. Create file README.md for github repository
*/
int readme(void);
/**
    3. Makefile create for run with utility Make
*/
int makefile(void);
/**
   4. Functia ruleaza programul din aceasta fila
*/
int run(void);
/**
    5. Convert file name to FILE
*/
void convertToUpperCase(char *sPtr);

#endif // ANTET_H_INCLUDED
