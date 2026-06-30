class Solution {
    public int strStr(String haystack, String needle) {
        if(haystack.length() < needle.length()) return -1;
        
        char[] hay = haystack.toCharArray();
        char[] nee = needle.toCharArray();

        for(int i = 0; i < hay.length; i++){
            int j = 0;
            while(j < needle.length() && (i + j) < hay.length){
                if(hay[i + j] == nee[j++]) continue;
                else{
                    j = -1;
                    break;
                }
            }
            if(j == needle.length()) return i;
        }
        return -1;

        // return haystack.indexOf(needle);
    }
}