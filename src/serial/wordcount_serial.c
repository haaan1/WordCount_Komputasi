#include <stdio.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char current, previous = ' ';
    long word_count = 0;

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: tidak dapat membuka file.\n");
        return 1;
    }

    clock_t start = clock();

    while ((current = fgetc(file)) != EOF) {
        if (!isspace(current) && isspace(previous)) {
            word_count++;
        }
        previous = current;
    }

    clock_t end = clock();
    double exec_time = (double)(end - start) / CLOCKS_PER_SEC;

    fclose(file);

    printf("Total kata (Serial): %ld\n", word_count);
    printf("Waktu eksekusi (Serial): %f detik\n", exec_time);

    return 0;
}
