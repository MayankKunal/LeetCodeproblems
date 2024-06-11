class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        
     List<Integer> ans = new ArrayList<>();
        Map<Integer, Integer> map = new TreeMap<>();

        // Count occurrences of each element in arr1
        for (int x : arr1) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        // Add elements from arr2 to the result in the order they appear in arr2
        for (int x : arr2) {
            while (map.getOrDefault(x, 0) > 0) {
                ans.add(x);
                map.put(x, map.get(x) - 1);
            }
        }

        // Add remaining elements to the result in sorted order
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            while (entry.getValue() > 0) {
                ans.add(entry.getKey());
                entry.setValue(entry.getValue() - 1);
            }
        }

        // Convert the result list to an array
        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }

        return result;
    
    }
}