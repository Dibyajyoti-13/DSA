class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int max_count = 0;
        for(int i : nums){
            if(i == 1) count++;
            else{
                if(max_count < count) max_count = count;
                count = 0;
            }
        }
        if(max_count < count) max_count = count;
        return max_count;
    }
}