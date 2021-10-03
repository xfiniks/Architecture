//
// Created by Иван Черных on 03.10.2021.
//
//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарника и его интерфейса
//------------------------------------------------------------------------------

#ifndef ARC_CHERNYKH_SHRUB_H
#define ARC_CHERNYKH_SHRUB_H

#include <stdio.h>

// кустарник
struct shrub {
    enum FLOWERING_MONTH {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
            AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER } floweringMonth; //месяц цветения
};

// Ввод параметров кустарника из файла
int InShrub(struct shrub *s, FILE *ifst);

// Случайный ввод параметров кустарника
void InRndShrub(struct shrub *s);

// Вывод параметров кустарника в форматируемый поток
void OutShrub(struct shrub *s, FILE *ofst);

#endif //ARC_CHERNYKH_SHRUB_H
