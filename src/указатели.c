#include <stdio.h>
#include <stdlib.h>

void createDATA(int*** data, const int size);
void freedata(int** data, const int size);

int main(void) {
    int data_size = 4;
    int** data = NULL;
    createDATA(&data, data_size);
    freedata(data, data_size);
    return 0;
}

void createDATA(int*** data, const int size) {
    *data = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        (*data)[i] = (int*)malloc(size * sizeof(int));
    }
}

void freedata(int** data, const int size) {
    for (int i = 0; i < size; i++) {
        free(data[i]);
    }
    free(data);
}