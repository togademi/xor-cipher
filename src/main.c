#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char byte;

#include "cipher.h"
#include "crack1.h"


int main(int argc, char const *argv[]) {
  int i, longClef, mode, cNumArgs=argc-2;
  char inputName[100], outputName[100], clef[20], OuiNonClef=0;
  byte message[256];

  if (argc == 1 || argc > 7 || (argc % 2 != 1)) {
    printf("ERROR: command line\n");
    exit(-1);
  }

  for (i=1; i<=cNumArgs; i=i+2) {
    if (strcmp(argv[i], "-l") == 0) {
      longClef = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-i") == 0) {
      strcpy(inputName, argv[i+1]);

    }
    else if (strcmp(argv[i], "-o") == 0) {
      strcpy(outputName, argv[i+1]);

    }
    else if (strcmp(argv[i], "-k") == 0) {
      strcpy(clef, argv[i+1]);
      OuiNonClef = 1;
    }
    else if (strcmp(argv[i], "-m") == 0) {
      mode = *argv[i+1];
    }
    else {
      printf("ERROR: command line\n");
      exit(-1);
    }
  }

  if ((OuiNonClef == 1) && (verifClef(clef, longClef) == 0)) {
    printf("ERROR: key\n");
    exit(-1);
  }

  FILE *input, *output;

  input = fopen(inputName, "r");
  output = fopen(outputName, "w");

  char c;

/* On lit le fichier input et on écrit son contenu dans message[] */
  if (input) {
    do {
      c = getc (input);
      message[i] = c;
      i++;
      } while (c != EOF);
    message[i] = '\0';
  }
  else {
    printf("ERROR: file\n");
    exit(-1);
  }

  if (!output) {
    printf("ERROR: file\n");
    exit(-1);
  }

  cipher(message, clef, input, output);

  if (mode == 1) {
    crack1(message, longClef);
  }

  fclose(input);
  fclose(output);


  return 0;
}
