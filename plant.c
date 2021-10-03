//
// Created by Иван Черных on 03.10.2021.
//

#include "plant.h"
#include "rnd.h"
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
// Ввод параметров обобщенного растения из файла

struct plant *InPlant(FILE *ifst) {
    struct plant *p;
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return ((void *) 0);

    char name[256];
    if (fscanf(ifst, "%s", name) == EOF)
        return ((void *) 0);

    switch (k) {
        case 1:p = (struct plant *) malloc(sizeof(struct plant));
            p->k = TREE;
            strcpy(p->name, name);
            if (InTree(&p->t, ifst) == EOF) {
                free(p);
                return ((void *) 0);
            }
            return p;
        case 2:p = (struct plant *) malloc(sizeof(struct plant));
            p->k = SHRUB;
            strcpy(p->name, name);
            if (InShrub(&p->s, ifst) == EOF) {
                free(p);
                return ((void *) 0);
            }
            return p;
        case 3:p = (struct plant *) malloc(sizeof(struct plant));
            p->k = FLOWER;
            strcpy(p->name, name);
            if (InFlower(&p->f, ifst) == EOF) {
                free(p);
                return ((void *) 0);
            }
            return p;
        default:return ((void *) 0);
    }
}

// Случайный ввод обобщенного растения
struct plant *InRndPlant() {
    const int NAME_LENGTH = 11;

    struct plant *p;
    int k = RandomRange(1, 3);
    switch (k) {
        case 1:p = (struct plant *) malloc(sizeof(struct plant));
            p->k = TREE;
            RandomString(p->name, NAME_LENGTH);
            InRndTree(&p->t);
            return p;
        case 2:p = (struct plant *) malloc(sizeof(struct plant));
            p->k = SHRUB;
            RandomString(p->name, NAME_LENGTH);
            InRndShrub(&p->s);
            return p;
        case 3:p = (struct plant *) malloc(sizeof(struct plant));
            p->k = FLOWER;
            RandomString(p->name, NAME_LENGTH);
            InRndFlower(&p->f);
            return p;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего животного в поток
void OutPlant(struct plant *p, FILE *ofst) {
    switch (p->k) {
        case TREE:OutTree(&p->t, ofst);
            break;
        case SHRUB:OutShrub(&p->s, ofst);
            break;
        case FLOWER:OutFlower(&p->f, ofst);
            break;
        default:fprintf(ofst, "Incorrect flower!\n");
            return;
    }

    fprintf(ofst, " Name = %s. Task result: %f\n", p->name, CalculateQuotient(p));
}

//------------------------------------------------------------------------------
// Реализация общей функции
double CalculateQuotient(struct plant *p) {
    double vowelsCount = 0;
    char vowels[max_name_len] = "aeyuioAEYUIO";
    for (int i = 0; i < strlen(p->name); i++) {
        if (p->name[i] == vowels[0] || p->name[i] == vowels[1] || p->name[i] == vowels[2] ||
        p->name[i] == vowels[3] || p->name[i] == vowels[4]  || p->name[i] == vowels[5] ||
        p->name[i] == vowels[6] || p->name[i] == vowels[7] || p->name[i] == vowels[8] ||
        p->name[i] == vowels[9] || p->name[i] == vowels[10]  || p->name[i] == vowels[11]) {
            vowelsCount++;
        }
    }
    return (double)vowelsCount / (double)strlen(p->name);
}
