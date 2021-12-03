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

    return 0;
}
