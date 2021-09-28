#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 29
#define MAX_PARTS 10

struct person {
    char name[NAME_LEN+1];
    char nation[NAME_LEN+1];
    int birth;
    char pic[NAME_LEN+1];
} p[MAX_PARTS];

void setPersonsStruct(FILE *file) {
    int i = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s %d %s", &p[i].name, &p[i].nation, &p[i].birth, &p[i].pic);
        i++;
    }
}

void getNextBirth(int *next) {
    int m, dif = 0;
    for (int i = 0; i < 9; ++i) {
        dif += abs(p[i].birth - p[i+1].birth);
    }
    m = dif/10;
    *next = p[9].birth + m;
}


int main() {
    int next;

    FILE *file = fopen("/uploads/personalidades.txt", "r");
    if (file) {
        setPersonsStruct(file);
        fclose(file);
    } else {
        printf("Couldn't open file\n");
        return 1;
    }

    getNextBirth(&next);
    printf("The next year of birth is: %d\n", next);

    return 0;
}