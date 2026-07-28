class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        int ans = 0;
        int bestFirst = 0;
        int bestSecond = 0;

        for (int i = firstLen + secondLen; i <= n; i++) {
            bestFirst = max(bestFirst, prefix[i - secondLen] - prefix[i - secondLen - firstLen]);
            int second = prefix[i] - prefix[i - secondLen];
            ans = max(ans, bestFirst + second);
        }

        for (int i = firstLen + secondLen; i <= n; i++) {
            bestSecond = max(bestSecond, prefix[i - firstLen] - prefix[i - firstLen - secondLen]);
            int first = prefix[i] - prefix[i - firstLen];
            ans = max(ans, bestSecond + first);
        }
        return ans;
    }
};