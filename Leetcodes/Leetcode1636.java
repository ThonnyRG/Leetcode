class Solution {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        
        // Contar las frecuencias de cada número en el array
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        // Crear una lista a partir del array original
        List<Integer> outputArray = new ArrayList<>();
        for (int num : nums) {
            outputArray.add(num);
        }

        // Ordenar la lista utilizando el comparador personalizado
        Collections.sort(outputArray, new SortComparator(map));
        
        // Convertir la lista ordenada de nuevo a un array
        int[] result = new int[nums.length];
        for (int i = 0; i < outputArray.size(); i++) {
            result[i] = outputArray.get(i);
        }
        
        return result;
    }
    
    class SortComparator implements Comparator<Integer> {
        private final Map<Integer, Integer> freqMap;

        // Asignar el mapa especificado
        SortComparator(Map<Integer, Integer> tFreqMap) {
            this.freqMap = tFreqMap;
        }

        // Comparar los valores
        @Override
        public int compare(Integer k1, Integer k2) {
            // Comparar por frecuencia
            int freqCompare = freqMap.get(k1).compareTo(freqMap.get(k2));
            
            // Si las frecuencias son iguales, comparar por valor en orden decreciente
            if (freqCompare == 0) {
                return k2.compareTo(k1);
            } else {
                return freqCompare;
            }
        }
    }
}