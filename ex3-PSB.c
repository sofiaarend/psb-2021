#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char *name;
    char *nation;
    char *birth;
    char *pic;
};

void setPersonsStruct(FILE *file, struct person *p[10]) {
    int i = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s %s %s", p[i]->name, p[i]->nation, p[i]->birth, p[i]->pic);
        i++;
    }
}

void getNextBirth(struct person *p[10], char *next) {
    int m, dif = 0;
    for (int i = 0; i < 10; ++i) {
        dif += labs(p[i]->birth - p[i+1]->birth);
    }
    m = dif/10;
    next = p[9]->birth + m;
}


int main() {
    struct person *p[10];
    char next;

    FILE *file = fopen("/aux/personalidades.txt", "r");
    if (file) {
        setPersonsStruct(file, p);
        fclose(file);
    } else {
        printf("Couldn't open file\n");
        return 1;
    }

    getNextBirth(p, &next);
    printf("The next year of birth is: %d\n", next);

    return 0;
}