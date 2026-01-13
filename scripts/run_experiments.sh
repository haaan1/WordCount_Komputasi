#!/bin/bash

INPUT=../data/input/WikipediaDatabase.txt

gcc ../src/serial/wordcount_serial.c -o wc_serial
gcc -fopenmp ../src/parallel/wordcount_omp.c -o wc_parallel
gcc -fopenmp ../src/optimized/wordcount_omp_optimized.c -o wc_optimized

echo "=== SERIAL ==="
./wc_serial $INPUT

echo "=== PARALLEL ==="
for t in 1 2 4 8 16
do
  export OMP_NUM_THREADS=$t
  echo "Threads: $t"
  ./wc_parallel $INPUT
done

echo "=== OPTIMIZED ==="
for t in 1 2 4 8 16
do
  export OMP_NUM_THREADS=$t
  echo "Threads: $t"
  ./wc_optimized $INPUT
done
