#include <stdio.h>
#include <stdlib.h>

/*preenche matriz aqui*/

int* transposta(int* va, int n, int m){
    int tr = alocaMatrizV(n, m);
    if(tr == NULL){
        return NULL;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            tr[i*n+j] = va[j*m+i];
        }
    }
    return tr;
}