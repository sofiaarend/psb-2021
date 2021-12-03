/* tg - tag cloud generator
   This program was developed for educational reasons, as a project
   for Programação de Software Basico at PUCRS, December 2021.
   Shaihan Buenos, Sofia Arend, Vinicio Muller */

#include <config.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

/* The official name of this program.s */
#define PROGRAM_NAME "tg"

#define AUTHORS \
    proper_name ("Shaihan Buenos"), \
    proper_name ("Sofia Arend"), \
    proper_name ("Vinicio Muller")

static struct option const long_options[] =
{
  {"tg", required_argument, NULL, 0},
  {GETOPT_HELP_OPTION_DECL},
  {GETOPT_VERSION_OPTION_DECL},
  {NULL, 0, NULL, 0}
};


void usage (int status) {
    if (status != EXIT_SUCCESS) {
      emit_try_help ();
    } else {
        printf (_("\
            Usage: %s [FILE]\n\
        "), program_name, program_name);
        fputs (_("\
            Generate a file with a tag cloud with the words in the given FILE.\n\
        "), stdout);
    }
}

void getFrequency(char word){
    char word[qtd],   aux[20],
         matriz[20][1][20]={0};

    int i,soma=0,w=0,k ,
        vetor[80]={0},f;

    printf("Type : ");
    fgets(word, qtd, stdin);

    for(i=0; i<strlen(word); i++){

        aux[w]=word[i];

        if(word[i] == ' ' || word[i] == '\n'){
            aux[w]='\0';
            strcpy(matriz[soma][0],aux);
            soma++;
            w=-1;
        }

        w++;
}

int main(int argc, char argv) {
   FILE *output = fopen("new-tgc.csv", "w");
    if (!output) {
        printf("Couldn't create output file\n");
        return 1;
    }

    FILE *file = fopen(argv, "r");
    if (file) {
        fseek (file, 0, SEEK_END);
        length = ftell (file);
        fseek (file, 0, SEEK_SET);

        string = malloc (length);
        if (string) {
            fread (string, 1, length, file);
        }
    }
    else {
        printf("Couldn't open file\n");
        return 1;
    }

    getFrequency(_argv);

    return 0;
}
