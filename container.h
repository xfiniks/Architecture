//
// Created by Иван Черных on 03.10.2021.
//

#ifndef ARC_CHERNYKH_CONTAINER_H
#define ARC_CHERNYKH_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "plant.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum { max_len = 10000 }; // максимальная длина
    int len; // текущая длина
    struct plant *cont[max_len];
};

// Инициализация контейнера
void InitContainer(struct container *c);

// Очистка контейнера от элементов (освобождение памяти)
void ClearContainer(struct container *c);

// Ввод содержимого контейнера из указанного потока
void InContainer(struct container *c, FILE *ifst);

// Случайный ввод содержимого контейнера
void InRndContainer(struct container *c, int size);

// Вывод содержимого контейнера в указанный поток
void OutContainer(struct container *c, FILE *ofst);

// Сортировка шеллом по возрастанию
void ShellSortContainer(struct container *c);

#endif //ARC_CHERNYKH_CONTAINER_H
