class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder str = new StringBuilder();

        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);

            if(Character.isLetterOrDigit(c)){
                str.append(Character.toLowerCase(c));
            }
        }
        String original = str.toString();
        String reversed = new StringBuilder(original).reverse().toString();

        return original.equals(reversed);
    }
}