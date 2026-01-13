#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char *buffer;
    long size;
    long total_count = 0;

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: tidak dapat membuka file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    buffer = (char *)malloc(size * sizeof(char));
    fread(buffer, sizeof(char), size, file);
    fclose(file);

    double start = omp_get_wtime();

    #pragma omp parallel for reduction(+:total_count)
    for (long i = 0; i < size; i++) {
        if (!isspace(buffer[i]) &&
            (i == 0 || isspace(buffer[i - 1]))) {
            total_count++;
        }
    }

    double end = omp_get_wtime();

    printf("Total kata (Optimized OpenMP): %ld\n", total_count);
    printf("Waktu eksekusi (Optimized): %f detik\n", end - start);

    free(buffer);
    return 0;
}
