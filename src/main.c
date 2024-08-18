#include <stdio.h>

int deg(int number, int degree);

int main(void) {
    int number = 0, degree = 0, flag = 0;

    printf("----> Введите число X и его степень N через пробел: ");
    if (!scanf("%d%d", &number, &degree)) {
        flag = 1;
    }

    if (flag == 1 || degree < 0) {
        printf("----> Error\n");
    } else {
        printf("----> Число %d в степени %d = %d\n", number, degree, deg(number, degree));
    }
    return 0;
}

int deg(int number, int degree) {
    int temp = 1;
    while (degree != 0) {
        temp *= number;
        degree--;
    }
    return temp;
}

/*

int deg(int number, int degree, int* temp) {
    if (degree != 0) {
        *temp *= number;
        return ssss(number, degree - 1, temp); // Как избавиться от данного return'a?
    } else {
        return 0;
    }
}

 */