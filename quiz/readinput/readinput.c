/* Copyright (c) 2020, Patrik Nyström
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

#define BUFFER_SIZE 40

// Read string input (with buffer overflow protection)
// Manual free() required
char* readStrInput(void) {
    char* buf = malloc(sizeof(char) * BUFFER_SIZE);
    memset(buf, 0, BUFFER_SIZE);

    char* result = NULL;
    while (result == NULL) {
        result = fgets(buf, BUFFER_SIZE, stdin);
        if (buf[strlen(buf) - 1] != '\n') {

            char c;
            while ((c = getchar()) != '\n' && c != EOF);

            fprintf(stderr, "Input was too long, try again!\n");
            result = NULL;
            continue;
        }
        break;
    }
    return buf;
}

// Read integer input to a variable (with integer overflow and underflow protection)
void readIntInput(int* number) {
    char* buf = malloc(sizeof(char) * BUFFER_SIZE);
    memset(buf, 0, BUFFER_SIZE);

    char* result = NULL;
    long longNum = 0;
    while (result == NULL) {
        result = fgets(buf, BUFFER_SIZE, stdin);
        if (buf[strlen(buf) - 1] != '\n') {

            char c = 0;
            while ((c = getchar()) != '\n' && c != EOF);

            fprintf(stderr, "Input was too long, try again!\n");
            result = NULL;
            continue;
        }

        char* endptr = NULL;

        // Check for integer input
        longNum = strtol(result, &endptr, 10);
        if (endptr == result || *endptr != '\n') {
            fprintf(stderr, "Input was not an integer, try again!\n");
            result = NULL;
            continue;
        } else {
            // Check for possible integer overflow or underflow
            if (longNum > INT_MAX) {
                fprintf(stderr, "Integer overflow detected! Try again!\n");
                result = NULL;
                continue;
            } else if (longNum < INT_MIN) {
                fprintf(stderr, "Integer underflow detected! Try again!\n");
                result = NULL;
                continue;
            }
        }

        break;
    }
    *number = (int) longNum;
    free(buf);
}

// Read double input to a variable (with double overflow and underflow protection)
void readDoubleInput(double* number) {
    char* buf = malloc(sizeof(char) * BUFFER_SIZE);
    memset(buf, 0, BUFFER_SIZE);

    char* result = NULL;
    double doubleNum = 0.0;
    while (result == NULL) {
        result = fgets(buf, BUFFER_SIZE, stdin);
        if (buf[strlen(buf) - 1] != '\n') {

            char c = 0;
            while ((c = getchar()) != '\n' && c != EOF);

            fprintf(stderr, "Input was too long, try again!\n");
            result = NULL;
            continue;
        }

        char* endptr = NULL;

        // Check for double input
        doubleNum = strtod(result, &endptr);
        if (endptr == result || *endptr != '\n') {
            fprintf(stderr, "Input was not a double, try again!\n");
            result = NULL;
            continue;
        } else {
            // Check for possible double overflow or underflow
            if (doubleNum > DBL_MAX) {
                fprintf(stderr, "double overflow detected! Try again!\n");
                result = NULL;
                continue;
            } else if (doubleNum < DBL_MIN) {
                fprintf(stderr, "double underflow detected! Try again!\n");
                result = NULL;
                continue;
            }
        }

        break;
    }
    *number = doubleNum;
    free(buf);
}
