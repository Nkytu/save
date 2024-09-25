#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int ordenar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool verifica_sequencia(int *sequencia, const char *arquivoSeq) {
    FILE *seqFile = fopen(arquivoSeq, "r");
    
    int numeros[6];
    while (fscanf(seqFile, "%d %d %d %d %d %d", &numeros[0], &numeros[1], &numeros[2], &numeros[3], &numeros[4], &numeros[5]) == 6) {
        if (memcmp(sequencia, numeros, 6 * sizeof(int)) == 0) {
            fclose(seqFile);
            return true;
        }
    }

    fclose(seqFile);
    return false;
}

int main() {

    srand(time(0));

    FILE *arquivo = fopen("seq.txt", "w");

    for (int linha = 0; linha < 10000; linha++) {
        int numeros[6];
        int contador = 0;

        while (contador < 6) {
            int numerorand = (rand() % 60) + 1;

            int gerado = 0;
            for (int j = 0; j < contador; j++) {
                if (numeros[j] == numerorand) {
                    gerado = 1;
                    break;
                }
            }

            if (gerado == 0) {
                numeros[contador++] = numerorand;
            }
        }
    

        qsort(numeros, 6, sizeof(int), ordenar);

        for (int i = 0; i < 6; i++) {
            fprintf(arquivo, "%d ", numeros[i]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);

    int sequencia[6];
    FILE *sorteioFile = fopen("sorteio.txt", "r");

    if (verifica_sequencia(sequencia, "seq.txt")) {
        printf("Vencedor do sorteio!");
    } else {
        printf("Desculpe, sem vencedor aqui.");
    }

    return 0;
}
