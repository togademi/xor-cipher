#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef unsigned char byte;

#include "cipher.h"
#include "crack1.h"


int main(int argc, char const *argv[]) {

  int i, mode, cNumArgs=argc-2;
  size_t longClef;
  char inputName[100], outputName[100], clef[20], OuiNonClef=0, isThereOutput=0;
  byte message[255];

  /* Si le nombre d'arguments est impair, supérieur à 7 ou égal à 1, alors erreur */
  if (argc == 1 || argc > 7 || (argc % 2 != 1)) {
    printf("ERROR: command line\n");
    exit(-1);
  }

  /* Scraping of the command line arguments */
  /* Boucle 'for' passant deux par deux par les arguments command line */
  for (i=1; i<=cNumArgs; i=i+2) {
    if (strcmp(argv[i], "-l") == 0 && OuiNonClef == 0) { /* Longueur clef */
      longClef = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-i") == 0) { /* Input file */
      strcpy(inputName, argv[i+1]);
    }
    else if (strcmp(argv[i], "-o") == 0) { /* Output file */
      strcpy(outputName, argv[i+1]);
      isThereOutput = 1;
    }
    else if (strcmp(argv[i], "-k") == 0) { /* Clef */
      strcpy(clef, argv[i+1]);
      OuiNonClef = 1;
      longClef = strlen(clef);
    }
    else if (strcmp(argv[i], "-m") == 0) { /* Mode */
      mode = *argv[i+1];
    }
    else {
      printf("ERROR: command line\n");
      exit(-1);
    }
  }

  /* Si il y a une clef et la clef est invalide, alors erreur de clef */
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


  // L'horloge commence
  clock_t begin = clock();

  /* Si il y a un fichier d'output, alors c'est le chiffrage/déchiffrage que s'execute */
  if (isThereOutput == 1) {
    cipher(message, clef, input, output);
  }

  else if (mode == 1) {
    crack1(message, longClef);
  }

  // L'horloge s'arrete
  clock_t end = clock();

  // Temps ecoule
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("Temps d'execution : %f secondes\n", time_spent);

  fclose(input);
  fclose(output);


  return 0;
}
