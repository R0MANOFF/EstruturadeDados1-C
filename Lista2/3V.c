#include <stdio.h>

int* diagonaldaMatriz(int *va, int n, int m){
    int aux;
    if(n < m){
        aux = n;
    }else {
        aux = m;
    }
    if(n == m){
        int dm = alocaVetor(aux);
        if(dm == NULL){
            return NULL;
        }
        for(int i = 0; i < aux; i++){
            dm[i] = va[im+i];
        }
        return dm;
    }
    return NULL;
}