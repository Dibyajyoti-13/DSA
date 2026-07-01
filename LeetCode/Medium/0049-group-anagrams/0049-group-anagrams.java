class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();

        int i = 0;
        for (String s : strs) {
            char[] ch = s.toCharArray();
            Arrays.sort(ch);
            String key = new String(ch);

            if (map.containsKey(key)) {
                result.get(map.get(key)).add(s);
            } else {
                result.add(new ArrayList<>());
                result.get(i).add(s);
                map.put(key, i);
                i++;
            }
        }

        return result;
    }
}