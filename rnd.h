//
// Created by Иван Черных on 03.10.2021.
//
//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел и строк
//------------------------------------------------------------------------------
#ifndef ARC_CHERNYKH_RND_H
#define ARC_CHERNYKH_RND_H

#include <stdlib.h>

// Случайное число в диапазоне [min; max]
static inline int RandomRange(long long min, long long max) {
    return rand() % (max - min + 1) + min;
}

// Случайная строка. Использует выделенную память.
char *RandomString(char *str, size_t size);

#endif //ARC_CHERNYKH_RND_H
