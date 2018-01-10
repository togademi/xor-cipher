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
    // while (feof(input) == 0) {
    //   //while ((c = fgetc(input)) != EOF) {
    //     c = fgetc(input);
    //     crypted[i] = c ^ clef[i];
    //     i++;
    //   }

      fwrite(crypted,1,256,output);
      crypted[i] = '\0';
  }



  // char coder[] = "polo";
  // // char decoder[] = "adios";
  // char clef[] = "traq";
  //
  // char output[4], output2[4];



  // for (i=0; i<4; i++) {
  //   output[i] = coder[i] ^ clef[i];
  //   output2[i] = output[i] ^ clef[i];
  // }
  //   printf("coder = %s\n", coder);
  //   printf("clef = %s\n", clef);
  // printf("texte chiffre = %s\n", output);
  // printf("texte d�chiffre = %s\n", output2);
  return 0;
}
