#ifndef FILEC_H_INCLUDED
#define FILEC_H_INCLUDED

#define __GNU__SOURCE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *program_invocation_short_name;

FILE *open_sesame(char *name);

#endif // FILEC_H_INCLUDED
