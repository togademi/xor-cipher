#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "crack1.h"

typedef unsigned char byte;

const byte admisClef[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,
83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,
106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,44,45,
46,58,63,95,123,125,48,49,50,51,52,53,54,55,56,57};

const byte admisMessage[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,
83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,
106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,44,45,
46,58,63,95,123,125,32,33,34,39,40,41,59,192,194,196,224,226,228,199,131,200,
201,202,203,232,233,234,235,206,207,238,239,217,219,249,251,212,214,244,246};

// Nombre de caractères admis pour la clef
const long int numClef = sizeof(admisClef) / sizeof(admisClef[0]);
// Nombre de caractères admis pour le message
const long int numMessage = sizeof(admisMessage) / sizeof(admisMessage[0]);

// void allocation(size_t longClef, int copieTab[3][100]) {
//   int i=0;
//   int ** tabClef = NULL;
//   tabClef = malloc(longClef * sizeof(byte));
//
//   if (tabClef == NULL) //Si l'allocation a echoue
//   {
//     printf("Allocation a echoue\n");
//     return; // On arrete immediatement le programme
//   }
//   // On peut continuer le programme normalement sinon
//
//   // Creer matrice
//   for (i=0; i<longClef; i++) {
//     tabClef[i] = malloc(100 * sizeof(byte));
//   }
//
//   /* Copie du tableau dans un pointeur pour le sortir de la fonction */
//   copieTab = tabClef;
// }

int verifClef(char clef[20], int longClef) {
  int i, j, compteur=0;

  for (i=0; i<longClef; i++) {
    for (j=0; j<numClef; j++) {
      if (clef[i] == admisClef[j]) {
        compteur++;
        break;
      }
    }
  }
  if ((compteur+1) == longClef) {
    return 1;
  }
  else {
    return 0;
  }
}


int crack1(byte message[], int longClef) {

  //char message[] = "  <k�";
  //size_t longMessage = strlen(message);
  //char clef[] = "x";
  //size_t longClef = strlen(clef);





  /*
  cMessage = compteur pour parcourir caracteres du message

  cClef = compteur pour parcourir tous les caracteres possibles d'une clef

  cCaractereMessage = compteur pour parcourir tous les caracteres possibles d'un message
  */
  int cMessage=0, cClef=0, cCaractereMessage=0, ligne=0, col=0;

  int tabClef[longClef][100];

  printf("longClef = %d\n", longClef);
  printf("numClef = %ld\n", numClef);
  printf("numMessage = %ld\n", numMessage);

  int i=0;

  /* On parcours le message caractere par caractere */
  for (cMessage=0; cMessage<256; cMessage++) {
    printf("Caractere message numero %d\n", cMessage);
    for (cClef=0; cClef<numClef; cClef++) {
      //printf("admisClef = %c - %d\n", admisClef[cClef],cClef);
      //printf("Caractere clef numero %d\n", cClef);
      printf("- %d -\n", i);
      i++;
      for (cCaractereMessage=0; cCaractereMessage<numMessage; cCaractereMessage++) {
        //printf("admisMessage = %c - %d\n", admisMessage[cCaractereMessage],cCaractereMessage);
        if ((message[cMessage] ^ admisClef[cClef]) == admisMessage[cCaractereMessage]) {
          tabClef[ligne][col] = admisClef[cClef];
          col++;
        }
      }
    }
    /* Si la clef est deja parcourue entierement, on recommence a la premiere ligne du tableau */
    if ((cMessage+1) % longClef == 0) {
      ligne = 0;
      col = 0;
    }
    else {
      ligne++;
      col = 0;
    }
  }
  for (ligne=0; ligne<longClef; ligne++) {
    for (col=0; col<100; col++) {
      printf("%c ", tabClef[ligne][col]);
    }
    printf("\n");
  }
  return 0;
}
