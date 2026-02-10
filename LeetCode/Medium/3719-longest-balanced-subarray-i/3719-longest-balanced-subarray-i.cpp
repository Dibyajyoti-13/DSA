class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            unordered_map<int, int> freq;
            int even = 0;
            int odd = 0;

            for(int j = i; j < n; j++){
                int x = nums[j];
                freq[x]++;
                if(freq[x] == 1){
                    if(x & 1) odd++;
                    else even++;
                }

                if(even == odd) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};