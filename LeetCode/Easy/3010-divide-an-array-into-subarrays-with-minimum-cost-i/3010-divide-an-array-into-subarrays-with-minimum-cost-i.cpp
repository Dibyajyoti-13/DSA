class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first_min = INT_MAX;
        int sec_min = INT_MAX;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < first_min){
                sec_min = first_min;
                first_min = nums[i];
            }
            else if(nums[i] < sec_min){
                sec_min = nums[i];
            }
        }
        return first_min + sec_min + nums[0];
    }
};