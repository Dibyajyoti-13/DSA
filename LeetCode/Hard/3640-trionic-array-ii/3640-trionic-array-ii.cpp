class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0;

        const long long NEG = -1e18;

        long long dp0 = nums[0];
        long long dp1 = NEG;
        long long dp2 = NEG;
        long long dp3 = NEG;

        long long ans = NEG;

        for (int i = 1; i < n; i++){
            long long ndp0 = nums[i];
            long long ndp1 = NEG;
            long long ndp2 = NEG;
            long long ndp3 = NEG;

            if (nums[i] > nums[i - 1]){
                ndp1 = max(dp0, dp1) + nums[i];
                ndp3 = max(dp2, dp3) + nums[i];
            }

            if (nums[i] < nums[i - 1]){
                ndp2 = max(dp1, dp2) + nums[i];
            }

            dp0 = ndp0;
            dp1 = ndp1;
            dp2 = ndp2;
            dp3 = ndp3;

            ans = max(ans, dp3);
        }
        return ans == NEG ? 0 : ans;
    }
};
