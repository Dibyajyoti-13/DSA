class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 0; int last = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(last != nums[i]){
                last = nums[i];
                swap(nums[i], nums[++c]);
            }
        }
        return ++c;
    }
};