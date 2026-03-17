// class Solution {
// public:
//     int sumSubseqWidths(vector<int>& nums) {
//         int m = 1000000007;
//         long long sum = 0;
//         int n = nums.size();

//         sort(nums.begin(), nums.end());
        
//         for (int i = 0; i < n; i++) {
//             sum = (sum + (long long)nums[i] * ((1LL << i) - (1LL << (n - i - 1)))) % m;
//             sum = (sum + (long long)nums[i] * ((1LL << i) - (1LL << (n - i - 1)))) % m;
//         }
        
//         return sum;
//     }
// };

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int m = 1000000007;
        long long sum = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        vector<long long> powerOf2(n);
        powerOf2[0] = 1;
        for (int i = 1; i < n; i++) {
            powerOf2[i] = (powerOf2[i - 1] * 2) % m;
        }
        
        for (int i = 0; i < n; i++) {
            sum = (sum + (long long)nums[i] * (powerOf2[i] - powerOf2[n - i - 1] + m) % m) % m;
        }
        
        return sum;
    }
};
