class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) return 0;
        else if(nums.length == 1) return nums[0];
        else if(nums.length == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        else if(nums.length == 3) return nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];

        int[] dp = new int[nums.length];
        
        dp[0] = nums[0]; 
        dp[1] = nums[1]; 
        dp[2] = nums[2] + nums[0];
        
        int ans = Math.max(dp[1], dp[2]);

        for(int i = 3; i < nums.length; i++){
            dp[i] = nums[i] + Math.max(dp[i - 2], dp[i - 3]);
            ans = Math.max(ans, dp[i]);
        }

        return ans;
    }
}