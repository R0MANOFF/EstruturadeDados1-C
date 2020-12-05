#include <stdio.h>

int*  linhadaMatriz(int *va, int n, int m, int l){
    int lm = alocaVetor(m);
    if(lm == NULL){
        return NULL;
    }
    for(int j = 0; j < m; j++){
        lm[j] = va[i*m+j];
    }
    return lm;
}