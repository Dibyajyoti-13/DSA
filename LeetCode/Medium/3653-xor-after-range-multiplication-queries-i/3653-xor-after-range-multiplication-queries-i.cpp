class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> mult(n, 1);

        for(auto &q : queries){
            int l = q[0], r = q[1], k = q[2], val = q[3];

            for(int i = l; i <= r; i += k){
                mult[i] = (mult[i] * val) % 1000000007;
            }
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            nums[i] = (nums[i] * mult[i]) % 1000000007;
            result ^= nums[i];
        }

        return result;
    }
};