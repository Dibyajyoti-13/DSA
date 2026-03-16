class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int high = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
            high = max(high, nums[i]);
        }

        int j = 1;
        while(j <= high){
            if(mp.find(j) == mp.end()) return j;
            j++;
        }

        return high + 1;
    }
};