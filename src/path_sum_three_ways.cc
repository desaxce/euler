#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deque>

#define MIN(a, b)   ((a) < (b) ? (a): (b))
#define N  80

using namespace std;

deque<deque<int> > matrix(N);
deque<int> table(N);
deque<int> nextTable(N);

int min(int k, int n) {
    int current;
    int result = matrix[k][n] + table[k];
    
    // Partie inferieure a k
    current = matrix[k][n] + table[k];
    for (int i = k-1; i > -1; --i) {
        current += -table[i+1]+matrix[i+1][n+1]+table[i];  
        if (current < result) {
            result = current;
        }
    }

    // Partie superieure a k
    current = matrix[k][n] + table[k];
    for (int i = k+1; i < N; ++i) {
        current += -table[i-1]+matrix[i-1][n+1]+table[i];
        if (current < result) {
            result = current;
        }
    }
    
    // == k
    if (matrix[k][n]+table[k] < result) {
        result = matrix[k][n]+table[k];
    }

    return result;
}

void loop() {
    // Initialisation
    for (int i = 0; i < N; ++i) {
        table[i] = matrix[i][N-1];
        // printf("%d ", table[i]);
    }
    // printf("\n");

    // Attention a l'indicage sur n (on va de droite (la fin) a gauche)
    for (int n = N-2; n > -1; --n) {
        // Pas tres beau d'utiliser deux tableaux
        // A changer si possible (faire les modifications en place)
        for (int k = 0; k < N; ++k) {
            nextTable[k] = min(k, n);
        }
        for (int k = 0; k < N; ++k) {
            table[k] = nextTable[k];
            // printf("%d ", table[k]);
        }
        // printf("\n");
    }
}

int main() {
    // Reads from stdin
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Computes the minimal paths in |table|
    loop();
    
    // Takes the minimal path among the N paths in |table|
    int result = table[0];
    for (int i = 0; i < N; ++i) {
        if (table[i] < result) {
            result = table[i];
        }
    }
    printf("min path sum = %d\n", result);

    return 0;
}

