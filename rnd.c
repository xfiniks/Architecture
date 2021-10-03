//
// Created by Иван Черных on 03.10.2021.
//

#include "rnd.h"
#include <string.h>

// Случайная строка. Использует выделенную память.
char *RandomString(char *str, size_t size) {
    const char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = RandomRange(0, strlen(charset) - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}