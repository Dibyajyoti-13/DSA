class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> n;

        for(int i : nums){
            auto it = lower_bound(n.begin(), n.end(), i);

            if(it == n.end()) n.push_back(i);
            else *it = i;
        }
        return n.size();
    }
};