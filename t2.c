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

void getFrequency(char text, FILE *output){
    if(!text) return;

    char aux[20], words[20][1][20]={0};

    int i, j = 0;
    int sum = 0, times[80] = {0};

    for(i = 0; i < strlen(text); i++) {
        aux[j] = text[i];
        if(text[i] == ' ' || text[i] == '\n') {
            aux[j]='\0';
            strcpy(words[sum][0], aux);
            sum++;
            j=-1;
        }
        j++;
    }
    for(j = 0; j < sum; j++) {
        if(!times[j]) times[j]++;  

        for(i = 0; i < sum; i++) {
            if(strcmp(words[j][0], words[i][0]) == 0 && j != i ) {
                times[j]++;
                strcpy(words[i][0], "");
            }
        }
    }
    for(w = 0; w < sum; w++) {
        if(strcmp(words[w][0],"") != 0){
            fprintf(output, "A Palavra ");
            fprintf(output, "%10s ", words[w][0]);

            fprintf(output, " Apareceu ");
            fprintf(output, "%2d ",times[w]);

            if (times[w] == 1) {
                fprintf(output, " Vez   ");
            } else {
                fprintf(output, " Vezes ");
            }

            fprintf(output, "Na Frase\n");
        }
    }
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

    getFrequency(string, output);

    return 0;
}
