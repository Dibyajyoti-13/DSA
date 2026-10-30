class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> mp = new HashMap<>();

        int n = s.length();
        int left = 0;
        int ans = 0;

        for(int right = 0; right < n; right++){
            char ch = s.charAt(right);

            if(mp.containsKey(ch) && mp.get(ch) >= left){
                left = mp.get(ch) + 1;
            }
            mp.put(ch, right);
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}