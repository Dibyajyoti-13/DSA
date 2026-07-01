class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int left = 0;
        HashSet<Character> store = new HashSet<>();
        char[] ch = s.toCharArray();

        for(int right = 0; right < s.length(); right++){
            while(store.contains(ch[right])){
                store.remove(ch[left]);
                left++;
            }
            store.add(ch[right]);
            ans = Math.max(ans, right - left + 1);
        }
        return ans;   
    }
}