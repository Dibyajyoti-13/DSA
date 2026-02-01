class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans;
        int largest = INT_MIN;
        int second_largest = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(largest < nums[i]){
                second_largest = largest;
                largest = nums[i];
                ans = i;
            }
            else if(second_largest < nums[i]) second_largest = nums[i];
        }

        if(largest >= 2 * second_largest) return ans;
        return -1;
    }
};