//
// Created by Иван Черных on 03.10.2021.
//
//------------------------------------------------------------------------------
// tree.c - содержит функции обработки дерева
//-------------------------------------------------------------------------------
#include "tree.h"
#include <string.h>
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров дерева из потока
int InTree(struct tree *t, FILE *ifst) {
    long long age;
    if (fscanf(ifst, "%lld", &age) == EOF)
        return EOF;

    if (age > 0) {
        t->age = age;
    } else {
        return 0;
    }
    return 1;
}

// Случайный ввод параметров дерева
void InRndTree(struct tree *t) {
    t->age = RandomRange(0, 9223372036854775807);
}

//------------------------------------------------------------------------------
// Вывод параметров дерева в поток
void OutTree(struct tree *t, FILE *ofst) {
    fprintf(ofst, "It is Tree: age = %lld.", t->age);
}

