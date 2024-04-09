class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> elements = new HashMap<>();
        for(int i : nums) {
            if(elements.containsKey(i)) {
                elements.put(i, elements.get(i) + 1);
            }
            else {
                elements.put(i, 1);
            }
        }

        int[] results = new int[k];
        Map<Integer, Integer> sortedMap =
                elements.entrySet().stream()
                        .sorted(Map.Entry.comparingByValue(Comparator.reverseOrder()))
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,
                                (e1, e2) -> e2, LinkedHashMap::new));

        int count = 0;
        for (Map.Entry<Integer, Integer> entry : sortedMap.entrySet()) {
            if(count >= k) {
                break;
            }
            Integer key = entry.getKey();
            results[count] = key;
            count++;
        }

        return results;
    }
}