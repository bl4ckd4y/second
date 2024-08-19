#include <stdio.h>
#include <stdlib.h>

void input(int* ptr_number, int* ptr_size);
void createDATA(int*** data, const int size);
void function1(int** data, const int n, const int data_size);
int min(int a, int b, int c, int d);
void function2(int** data, const int number, const int size);
void print(int** data, const int size);
void freedata(int** data, const int size);

int main() {
    int n, data_size;
    int** data = NULL;

    input(&n, &data_size);
    createDATA(&data, data_size);
    //    function1(data, n, data_size);
    function2(data, n, data_size);
    print(data, data_size);

    freedata(data, data_size);
    return 0;
}

void input(int* ptr_number, int* ptr_size) {
    scanf("%d", ptr_number);
    *ptr_size = (*ptr_number * 2 - 1);
}

void createDATA(int*** data, const int size) {
    *data = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        (*data)[i] = (int*)malloc(size * sizeof(int));
    }
}

void function1(int** data, const int number, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Вычисляем минимальное расстояние до границы
            int min_dist = i < j ? i : j;
            min_dist = min_dist < size - i ? min_dist : size - i - 1;
            min_dist = min_dist < size - j ? min_dist : size - j - 1;

            data[i][j] = number - min_dist;
        }
    }
}

int min(int a, int b, int c, int d) {
    int min_val = a;
    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;
    if (d < min_val) min_val = d;
    return min_val;
}

void function2(int** data, const int number, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Вычисляем расстояние до каждой из четырех границ
            int top_dist = i;                // Расстояние до верхней границы
            int left_dist = j;               // Расстояние до левой границы
            int bottom_dist = size - i - 1;  // Расстояние до нижней границы
            int right_dist = size - j - 1;   // Расстояние до правой границы

            // Нахождение минимального расстояния до любой из границ
            int min_dist = min(top_dist, left_dist, bottom_dist, right_dist);

            // Установка значения в массиве
            data[i][j] = number - min_dist;
        }
    }
}

void print(int** data, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void freedata(int** data, const int size) {
    for (int i = 0; i < size; i++) {
        free(data[i]);
    }
    free(data);
}