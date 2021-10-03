//
// Created by Иван Черных on 03.10.2021.
//

#ifndef ARC_CHERNYKH_PLANT_H
#define ARC_CHERNYKH_PLANT_H

//------------------------------------------------------------------------------
// plant.h - содержит описание обобщающего растения,
//------------------------------------------------------------------------------

#include <stdio.h>
#include "flower.h"
#include "shrub.h"
#include "tree.h"

//------------------------------------------------------------------------------
// структура, обобщающая все растения
struct plant {
    enum { max_name_len = 256 }; // максимальная длина имени

    enum KEY {TREE, SHRUB, FLOWER} k; // ключ
    char name[max_name_len];

    // используемые альтернативы
    union { // используем простейшую реализацию
        struct tree t;
        struct shrub s;
        struct flower f;
    };
};

// Ввод обобщенного растения
struct plant *InPlant(FILE *ifst);

// Случайный ввод обобщенного растения
struct plant *InRndPlant();

// Вывод обобщенного растения
void OutPlant(struct plant *a, FILE *ofst);

// Вычисление частного от деления числа гласных букв в названии на общую длину названия (действительное число)
double CalculateQuotient(struct plant *p);

#endif //ARC_CHERNYKH_PLANT_H
