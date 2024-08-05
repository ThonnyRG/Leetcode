import java.util.*;

class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> frequencyMap = new HashMap<>();
        
        for (String str : arr) {
            frequencyMap.put(str, frequencyMap.getOrDefault(str, 0) + 1);
        }
        
        List<String> distinctElements = new ArrayList<>();
        
        for (String str : arr) {
            if (frequencyMap.get(str) == 1) {
                distinctElements.add(str);
            }
        }
        
        if (distinctElements.size() >= k) {
            return distinctElements.get(k - 1);
        } else {
            return "";
        }
    }
}
