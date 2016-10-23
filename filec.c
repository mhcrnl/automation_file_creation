#include "filec.h"

FILE *
open_sesame (char *name)
{
  FILE *stream;
    int c;
  errno = 0;
  stream = fopen (name, "r");
  if (stream == NULL)
    {
      fprintf (stderr, "%s: Couldn't open file %s; %s\n",
               program_invocation_short_name, name, strerror (errno));
      exit (EXIT_FAILURE);
    }
  else{
    while(1){ c=fgetc(stream);
        if(feof(stream)){ break; }
        printf("%c", c);
    }
  return stream;
  }

}
