# Word Count Paralel dengan OpenMP

Proyek ini merupakan implementasi Word Count
menggunakan pemrograman paralel OpenMP.

## Struktur Folder
- src/serial      : Implementasi serial
- src/parallel    : Implementasi paralel OpenMP
- src/optimized   : Versi optimisasi
- data/input      : Dataset input
- data/result     : Hasil eksperimen
- scripts         : Script eksperimen dan visualisasi

## Compile
```bash
gcc src/serial/wordcount_serial.c -o wc_serial
gcc -fopenmp src/parallel/wordcount_omp.c -o wc_parallel
gcc -fopenmp src/optimized/wordcount_omp_optimized.c -o wc_optimized
# WordCount_Komputasi
# WordCount_Komputasi
# WordCount_Komputasi
