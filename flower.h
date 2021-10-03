//
// Created by Иван Черных on 03.10.2021.
//
//------------------------------------------------------------------------------
// flower.h - содержит описание цветка и его интерфейса
//------------------------------------------------------------------------------

#ifndef ARC_CHERNYKH_FLOWER_H
#define ARC_CHERNYKH_FLOWER_H

#include <stdio.h>

// цветок
struct flower {
    enum FLOWER_TYPE {DOMESTIC, GARDEN, WILD} type; //тип цветка
};

// Ввод параметров цветка из потока
int InFlower(struct flower *f, FILE *ifst);

// Случайный ввод параметров цветка
void InRndFlower(struct flower *f);

// Вывод параметров цветка в форматируемый поток
void OutFlower(struct flower *f, FILE *ofst);

#endif //ARC_CHERNYKH_FLOWER_H
