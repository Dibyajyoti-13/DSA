class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, j = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            while(j < n && nums[j] <= nums[i] * 1LL * k){
                j++;
            }
            ans = max(j - i, ans);
        }
        return n - ans;
    }
};