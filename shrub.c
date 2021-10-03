//
// Created by Иван Черных on 03.10.2021.
//
//------------------------------------------------------------------------------
// shrub.c - содержит процедуру ввода параметров
// для уже созданного кустарника
//------------------------------------------------------------------------------

#include <string.h>
#include "rnd.h"
#include "shrub.h"


//------------------------------------------------------------------------------
// Ввод параметров кустарника из файла
int InShrub(struct shrub *s, FILE *ifst) {
    char flowering_month[10];
    if (fscanf(ifst, "%s", flowering_month) == EOF)
        return EOF;

    if (strcmp(flowering_month, "JANUARY") == 0) {
        s->floweringMonth = JANUARY;
    } else if (strcmp(flowering_month, "FEBRUARY") == 0) {
        s->floweringMonth = FEBRUARY;
    } else if (strcmp(flowering_month, "MARCH") == 0) {
        s->floweringMonth = MARCH;
    } else if (strcmp(flowering_month, "APRIL") == 0) {
        s->floweringMonth = APRIL;
    } else if (strcmp(flowering_month, "MAY") == 0) {
        s->floweringMonth = MAY;
    } else if (strcmp(flowering_month, "JUNE") == 0) {
        s->floweringMonth = JUNE;
    } else if (strcmp(flowering_month, "JULY") == 0) {
        s->floweringMonth = JULY;
    } else if (strcmp(flowering_month, "AUGUST") == 0) {
        s->floweringMonth = AUGUST;
    } else if (strcmp(flowering_month, "SEPTEMBER") == 0) {
        s->floweringMonth = SEPTEMBER;
    } else if (strcmp(flowering_month, "OCTOBER") == 0) {
        s->floweringMonth = OCTOBER;
    } else if (strcmp(flowering_month, "NOVEMBER") == 0) {
        s->floweringMonth = NOVEMBER;
    } else if (strcmp(flowering_month, "DECEMBER") == 0) {
        s->floweringMonth = DECEMBER;
    }
    else {
        return 0;
    }

    return 1;
}

// Случайный ввод параметров кустарника
void InRndShrub(struct shrub *s) {
    int random = RandomRange(0,11);
    // Случайное месяц цветения
    s->floweringMonth = random;
}

//------------------------------------------------------------------------------
// Вывод параметров кустарника в форматируемый поток
void OutShrub(struct shrub *s, FILE *ofst) {
    char* floweringMonth;
    if (s->floweringMonth == JANUARY) {
        floweringMonth = "JANUARY";
    } else if (s->floweringMonth == FEBRUARY) {
        floweringMonth = "FEBRUARY";
    } else if (s->floweringMonth == MARCH) {
        floweringMonth = "MARCH";
    } else if (s->floweringMonth == APRIL) {
        floweringMonth = "APRIL";
    } else if (s->floweringMonth == MAY) {
        floweringMonth = "MAY";
    } else if (s->floweringMonth == JUNE) {
        floweringMonth = "JUNE";
    } else if (s->floweringMonth == JULY) {
        floweringMonth = "JULY";
    } else if (s->floweringMonth == AUGUST) {
        floweringMonth = "AUGUST";
    } else if (s->floweringMonth == SEPTEMBER) {
        floweringMonth = "SEPTEMBER";
    } else if (s->floweringMonth == OCTOBER) {
        floweringMonth = "OCTOBER";
    } else if (s->floweringMonth == NOVEMBER) {
        floweringMonth = "NOVEMBER";
    } else if (s->floweringMonth == DECEMBER) {
        floweringMonth = "DECEMBER";
    } else {
        floweringMonth = "WRONG_MONTH";
    }

    fprintf(ofst, "It is Shrub: flowering month = %s.", floweringMonth);
}
