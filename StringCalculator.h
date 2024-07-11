#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int add(char *numbers);

void test_empty_string();
void test_single_number();
void test_two_numbers();
void test_newline_between_numbers();
void test_different_delimiters();
void test_negative_numbers();
void test_numbers_bigger_than_1000();

int main() {
    test_empty_string();
    test_single_number();
    test_two_numbers();
    test_newline_between_numbers();
    test_different_delimiters();
    test_negative_numbers();
    test_numbers_bigger_than_1000();
    
    printf("All tests passed!\n");
    return 0;
}

int add(char *numbers) {
    if (numbers[0] == '\0') {
        return 0;
    }

    // Check if a custom delimiter is specified
    char delimiter = ',';
    if (strncmp(numbers, "//", 2) == 0) {
        // Custom delimiter case
        char *end_of_delimiter = strchr(numbers, '\n');
        if (end_of_delimiter != NULL) {
            delimiter = *(end_of_delimiter - 1);
            numbers = end_of_delimiter + 1;
        }
    }

    int sum = 0;
    char *token = strtok(numbers, "\n,");
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0) {
            fprintf(stderr, "negatives not allowed: %d\n", num);
            return 0;
        }
        if (num <= 1000) {
            sum += num;
        }
        token = strtok(NULL, "\n,");
    }

    return sum;
}

void test_empty_string() {
    assert(add("") == 0);
}

void test_single_number() {
    assert(add("5") == 5);
}

void test_two_numbers() {
    assert(add("2,3") == 5);
}

void test_newline_between_numbers() {
    assert(add("1\n2,3") == 6);
}

void test_different_delimiters() {
    assert(add("//;\n1;2") == 3);
    assert(add("//[]\n12***3") == 6);
}

void test_negative_numbers() {
    assert(add("1,-2,3") == 0); // Should print an error for -2 and return 0
}

void test_numbers_bigger_than_1000() {
    assert(add("2,1001") == 2); // 1001 should be ignored
}
