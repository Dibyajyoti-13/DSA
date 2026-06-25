class Solution {
    int[] helper(int[] digits, int n){
        if(digits[n - 1] != 9){
            digits[n - 1]++;
            return digits;
        }
        else{
            if(n == 1){
                int arr[] = new int[digits.length + 1];
                digits[n - 1] = 0;
                for(int i = digits.length; i > 0; i--){
                    arr[i] = digits[i - 1];
                }
                arr[0] = 1;
                return arr;
            }
            digits[n - 1 ] = 0;
            return helper(digits, n - 1);
        }
    }

    public int[] plusOne(int[] digits) {
        return helper(digits, digits.length);
    }
}