class Solution {
public:
    int calc(vector<int>& nums, int x){
        int n = nums.size();
        int count = 0;
        int total = 0;

        for(int i : nums){
            if(i <= x){
                count++;
                total += count;
            }
            else count = 0;
        }
        return total;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return calc(nums, right) - calc(nums, left - 1);
    }
};