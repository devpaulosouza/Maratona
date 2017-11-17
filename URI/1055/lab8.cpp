#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -2147483648

int _sum;

int abs (int a) {
    return (a<0)?a*-1:a;
}

void calculate_sum (int* vector, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum+=abs(vector[i]-vector[i+1]);
    }
    _sum = (sum > _sum) ? sum : _sum;
}

void swap (int* vector, int i, int j) {
    int aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
}

int permute (int* vector, int i, int n) {
    if (i == n) {
        calculate_sum(vector, n);
    } else {
        for (int j = i; j <=n; ++j) {
            swap(vector, i, j);
            permute(vector, i+1, n);
            swap(vector, i, j);
        }
    }
}

int tiny_sum (int* vector, int n) {
    permute(vector, 0, n-1);
    return _sum;
}

int main() {
    int* vector;
    int size, tests;
    scanf("%d", &tests);
    for(int i = 0; i < tests; ++i) {
        scanf("%d", &size);
        _sum = INT_MIN;
        vector = (int*) malloc(sizeof(int)*size);
        
        for(int j = 0; j < size; ++j) {
            scanf("%d", &vector[j]);
        }
        printf("Case %d: %d\n", i+1, tiny_sum(vector, size));
        free(vector);
        vector = NULL;
    }
    return 0;
}
