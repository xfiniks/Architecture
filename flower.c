//
// Created by Иван Черных on 03.10.2021.
//
//------------------------------------------------------------------------------
// flower.c - содержит процедуру ввода параметров
// для уже созданного цветка
//------------------------------------------------------------------------------

#include "flower.h"
#include <string.h>
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров цветка из файла
int InFlower(struct flower *f, FILE *ifst) {
    char flowerType[10];
    if (fscanf(ifst, "%s", flowerType) == EOF)
        return EOF;

    if (strcmp(flowerType, "DOMESTIC") == 0) {
        f->type = DOMESTIC;
    } else if (strcmp(flowerType, "GARDEN") == 0) {
        f->type = GARDEN;
    } else if (strcmp(flowerType, "WILD") == 0) {
        f->type = WILD;
    } else {
        return 0;
    }

    return 1;
}

// Случайный ввод параметров цветка
void InRndFlower(struct flower *f) {
    int random = RandomRange(0, 2);

    // Случайный тип цветка
    f->type = random;
}

//------------------------------------------------------------------------------
// Вывод параметров цветка в форматируемый поток
void OutFlower(struct flower *f, FILE *ofst) {
    char* flowerType;
    if (f->type == DOMESTIC) {
        flowerType = "DOMESTIC";
    } else if (f->type == GARDEN) {
        flowerType = "GARDEN";
    } else if (f->type == WILD) {
        flowerType = "WILD";
    } else {
        flowerType = "WRONG_TYPE";
    }

    fprintf(ofst, "It is Flower: type = %s.", flowerType);
}