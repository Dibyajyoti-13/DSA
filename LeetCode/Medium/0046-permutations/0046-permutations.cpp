class Solution {
public:
    vector<vector<int>> result;

    void helper(int start, vector<int>& nums){
        if(start == nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            helper(start + 1, nums);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(0, nums);
        return result;
    }
};