class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int lastGreater = -1;
        int lastInRange = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) lastGreater = i;
            if (nums[i] >= left) lastInRange = i;
            
            count += (lastInRange - lastGreater > 0) ? (lastInRange - lastGreater) : 0;
        }
        return count;
    }
};