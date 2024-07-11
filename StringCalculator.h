#include <stdio.h>
#include "StringCalculator.h"
#include <stdlib.h>
#include <string.h>

int add(const char* input) {
    if (input == NULL || strcmp(input, "") == 0) {
        return 0;
    }

    int sum = 0;
    char *buffer = strdup(input); // Make a copy since strtok modifies the string
    char *token = strtok(buffer, ",\n"); // Tokenize by comma or newline

    while (token != NULL) {
        int num = atoi(token);
        if (num <= 1000) { // Ignore numbers greater than 1000
            sum += num;
        }
        token = strtok(NULL, ",\n");
    }

    free(buffer); // Free allocated memory
    return sum;
}

