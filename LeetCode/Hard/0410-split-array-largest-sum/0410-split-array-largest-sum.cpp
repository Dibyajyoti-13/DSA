class Solution {
public:
    int calc(vector<int> nums, int x){
        int partitions = 1;
        int sum = 0;
        for(int i : nums){
            if(sum + i > x){
                partitions++;
                sum = i;
            }
            else sum += i;
        }
        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;

        for(int i : nums){
            low = max(low, i);
            high += i;
        }

        int ans = high;

        while(low <= high){
            int mid = low + (high - low) /2;

            if(calc(nums, mid) <= k){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};