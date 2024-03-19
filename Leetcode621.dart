import 'dart:math';

class Solution {
  int leastInterval(List<String> tasks, int n) {
    // Construir el array de frecuencia
    List<int> freq = List<int>.filled(26, 0);
    for (String task in tasks) {
      freq[task.codeUnitAt(0) - 'A'.codeUnitAt(0)]++;
    }
    freq.sort(); // Ordenar para obtener la frecuencia máxima
    int maxFreq = freq[25];
    int idleTime = (maxFreq - 1) * n; // ej: A : 3, n=2 -> A_ _A_ _A

    for (int i = 24; i >= 0; i--) {
      // Math.min maneja el caso en el que otra tarea tiene la misma frecuencia
      idleTime -= min(maxFreq - 1, freq[i]);
    }
    // El tiempo de espera no puede ser negativo, se limita a 0
    return tasks.length + max(idleTime, 0);
  }
}
