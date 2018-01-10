#include <stdio.h>
#include <stdlib.h>
typedef unsigned char byte;

#include "cipher.h"

int cipher(byte message[256], char clef[], FILE *input, FILE *output) {
  char c, crypted[256];

  int i=0;
  if (input) {
    do {
      c = getc (input);
      crypted[i] = c ^ clef[i];
      i++;
      } while (c != EOF);

      fwrite(crypted,1,256,output);
      crypted[i] = '\0';
  }

  return 0;
}
