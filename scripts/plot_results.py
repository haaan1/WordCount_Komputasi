import matplotlib.pyplot as plt

# Data eksperimen
threads = [1, 2, 4, 8]
serial_time = 5.5
parallel_time = [5.5, 3.0, 1.9, 1.5]
optimized_time = [5.5, 2.6, 1.5, 1.2]

# Buat list serial agar panjangnya sama dengan threads
serial_times = [serial_time for _ in threads]

# Plot
plt.plot(threads, serial_times, label="Serial")
plt.plot(threads, parallel_time, label="Parallel")
plt.plot(threads, optimized_time, label="Optimized")

# Label dan judul
plt.xlabel("Jumlah Thread")
plt.ylabel("Waktu Eksekusi (detik)")
plt.title("Perbandingan Kinerja Word Count Serial vs Paralel OpenMP")

# Legend dan grid
plt.legend()
plt.grid(True)

# Tampilkan grafik
plt.show()
