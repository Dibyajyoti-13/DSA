class Solution {
    int helper(int num){
        if(num <= 9) return num;

        int sum = 0;
        while(num != 0){
            sum += num % 10;
            num = num / 10;
        }
        return helper(sum);
    }

    public int addDigits(int num) {
        return helper(num);
    }
}