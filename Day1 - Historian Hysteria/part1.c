#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *arq = fopen("input.txt", "r");
    if (arq == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int *esq = NULL;
    int *dir = NULL;
    int n = 0;

    char linha[1000];
    while (fgets(linha, sizeof(linha), arq)) {
        int a, b;
        if (sscanf(linha, "%d %d", &a, &b) == 2) {
            esq = realloc(esq, (n + 1) * sizeof(int));
            dir = realloc(dir, (n + 1) * sizeof(int));
            if (esq == NULL || dir == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
            esq[n] = a;
            dir[n] = b;
            n++;
        }
    }

    fclose(arq);

    // Ordena cada array individualmente
    qsort(esq, n, sizeof(int), cmpfunc);
    qsort(dir, n, sizeof(int), cmpfunc);
    
    

    printf("Lados Ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n ", esq[i], dir[i]);
    }
    printf("\n");

    int total_diff = 0;
printf("Diferenças correspondentes (valores absolutos):\n");
for (int i = 0; i < n; i++) {
    int diff = abs(dir[i] - esq[i]);  // diferença absoluta
    printf("%d\n", diff);
    total_diff += diff;
}
printf("\nSoma total das diferenças absolutas: %d\n", total_diff);

    free(esq);
    free(dir);

    return 0;
}

