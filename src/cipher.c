#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char byte;

#include "cipher.h"

int cipher(byte message[255], char clef[], FILE *input, FILE *output) {
  char c, crypted[255];

  /* Longueur de la clef */
  size_t longClef = strlen(clef);

  int i=0, j=0;
  if (input) { // Si le fichier input est valide
    do {
      c = getc (input);
      /* Faire XOR Cipher de chaque caractère de l'input avec chaque caractère de la clef */
      crypted[i] = c ^ clef[j];
      i++;

      /* Si fin de la clef, son compteur est remis a zero */
      if (j+1 == longClef) {
        j = 0;
      }
      else {
        j++;
      }

      } while (c != EOF);

      /* Le contenu de crypted[] est ecrit dans le fichier output */
      fwrite(crypted,1,255,output);
      crypted[i] = '\0';
  }

  return 0;
}
