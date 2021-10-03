//
// Created by Иван Черных on 03.10.2021.
//
//------------------------------------------------------------------------------
// tree.h - содержит описание дерева
//------------------------------------------------------------------------------

#ifndef ARC_CHERNYKH_TREE_H
#define ARC_CHERNYKH_TREE_H

#include <stdio.h>
#include <stdbool.h>

struct tree{
    long long age; // возраст
};

// Ввод параметров дерева из файла
int InTree(struct tree *t, FILE *ifst);

// Случайный ввод параметров дерева
void InRndTree(struct tree *t);

// Вывод параметров дерева в форматируемый поток
void OutTree(struct tree *t, FILE *ofst);

#endif //ARC_CHERNYKH_TREE_H
