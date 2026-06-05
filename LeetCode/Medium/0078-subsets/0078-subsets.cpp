class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void helper(vector<int> nums, int start){
        result.push_back(temp);

        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            helper(nums, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        helper(nums, 0);
        return result;
    }
};