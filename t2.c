/* tg - tag cloud generator
   This program was developed for educational reasons, as a project
   for Programação de Software Basico at PUCRS, December 2021.
   Shaihan Buenos, Sofia Arend, Vinicio Muller */

#include <config.h>
#include <stdio.h>
#include <getopt.h>

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


void
usage (int status) {
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

int main() {

    return 0;
}