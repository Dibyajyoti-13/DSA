class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i = 0; i < queries.size(); i++){
            int idx = queries[i][0];

            while(idx <= queries[i][1]){
                nums[idx] = (nums[idx] * 1LL * queries[i][3]) % (1000000007);
                idx += queries[i][2];
            }
        }
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            result ^= nums[i];
        }
        return result;
    }
};