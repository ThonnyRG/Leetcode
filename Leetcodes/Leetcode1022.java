class Solution {
    private int rank(HashMap<Integer, Integer> map, int a) {
        return map.containsKey(a) ? map.get(a) : map.size();
    }
    
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) {
            map.put(arr2[i], i);
        }

        List<Integer> arr1List = Arrays.stream(arr1).boxed().collect(Collectors.toList());
        arr1List.sort(new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                int rankA = rank(map, a);
                int rankB = rank(map, b);
                return rankA == rankB ? a.compareTo(b) : Integer.compare(rankA, rankB);
            }
        });
        
        return arr1List.stream().mapToInt(Integer::intValue).toArray();
    }
}