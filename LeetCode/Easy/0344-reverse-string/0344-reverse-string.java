class Solution {
    public void reverseString(char[] s) {
        int n = s.length - 1;
        for(int i = 0; i <= n / 2; i++){
            char ch = s[n - i];
            s[n - i] = s[i];
            s[i] = ch;
        }
    }
}