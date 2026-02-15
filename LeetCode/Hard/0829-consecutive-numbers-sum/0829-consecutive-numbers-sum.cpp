class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int k = 1;
        for(int i = 1; i < n/2; i++){
            if(n % i == 0) k++;
        }
        return k;
    }
};