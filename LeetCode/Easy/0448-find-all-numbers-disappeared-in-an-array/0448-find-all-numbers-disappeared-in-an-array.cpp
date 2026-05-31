class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;

        for(int i : nums){
            int index = abs(i) - 1;
            nums[index] = -abs(nums[index]);
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};