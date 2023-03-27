#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>

struct elems {
    int32_t size;
    int32_t* array;
};

/* checking repeating elements */

bool check_element(int32_t value, struct elems* el) {
    for (int32_t j = 0; j < el->size - 1; ++j) {
        if (el->array[j] == value) {
            puts("Repeated element in set!");
            return false;
        }
    }
    return true;
}

bool filling_set(struct elems *el) {
    for (int32_t n = 0; n < el->size; ++n) {
        int32_t value;
        scanf("%d", &value);
        bool isNorm = check_element(value, el);
        if (!isNorm) { //checking each element
            return 1;
        }
        else {
            el->array[n] = value;
        }
    }
    return 0;
}

void print_set(int32_t size, int8_t new_arr[size], int32_t dec) {
    printf("%d = ", dec);
    for (int32_t i = 0; i < size; ++i) {
        putchar(new_arr[i]);
    }
    putchar('\n');
}

void negative_num(int32_t size, int8_t new_arr[size]) {
    for (int32_t i = 0; i < size; ++i) {
        if (new_arr[i] == '0'){
            new_arr[i] = '1';
        } else {
            new_arr[i] = '0';
        }
    }
    for (int32_t i = size - 1; i >= 0; ++i) { //converting num < 0
        if (new_arr[i] == '0') {
            new_arr[i] = '1';
            break;
        } else {
            new_arr[i] = '0';
            if (i == 0) {
                putchar(1);
            }
        }
    }
}

void conversig_func(int32_t size, int32_t array_n, int8_t new_arr[size]) {
    if (array_n < 0) {
        array_n = abs(array_n);
    }
    for (int32_t j = 0; array_n > 0; ++j) {
        new_arr[size - 1 - j] = array_n % 2 + '0';
        array_n /= 2;
    }
}

void full_print(struct elems* el) {
    for (int32_t n = 0; n < el->size; ++n) {
        if (el->array[n] == 0) {
            puts("0 = 0");
            continue;
        }
        int32_t dec = el->array[n];
        int32_t new_arr_size = (int32_t)log2(abs(dec)) + 1; //finding size of string
        int8_t new_arr[new_arr_size];
        conversig_func(new_arr_size, el->array[n], new_arr);
        if (dec < 0){ //if num < 0
            negative_num(new_arr_size, new_arr);
        }
        print_set(new_arr_size, new_arr, dec);
    }
}
int main() {
    int32_t size;
    puts("Input size of set:");
    struct elems el;
    /* checking the size input */

    if (!scanf("%d", &el.size)) {
        puts("Invalid input!");
        return 0;
    }
    if (el.size <= 0) {
        puts("Invalid input!");
        return 0;
    }

    /* filling in the set */

    el.array = (int32_t*)malloc(size * sizeof(int32_t));
    puts("input set:");
    if (filling_set(&el)) {
        return 1;
    }

    /* conversion to binary */

    full_print(&el);

    return 0;
}