class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        int left_sum[] = new int[n];
        left_sum[0] = nums[0];
        for(int i = 1; i < n; i++){
            left_sum[i] = left_sum[i - 1] + nums[i];  
        }

        double max = left_sum[k - 1] / (double) k;
        for(int i = k; i < n; i++){
            max = Math.max(max, (left_sum[i] - left_sum[i - k]) / (double) k);
        }
        return max;
    }
}