#include "apue.h"
#include <stdlib.h>

extern char ** environ;

int main(int argc, char * argv[])
{
  char ** p = environ;
  while (*p != NULL) {
    printf("%s\n", *p);
    ++p;
  }
  return EXIT_SUCCESS;
}
