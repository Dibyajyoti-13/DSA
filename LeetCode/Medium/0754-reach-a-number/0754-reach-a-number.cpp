class Solution {
public:
    int reachNumber(int target) {

        auto getSum = [](int n) -> int {
            return n * (n + 1) / 2;
        };

        target = abs(target);

        int ans = 0;
        while(getSum(ans) < target || (getSum(ans) - target & 1)) ans++;

        return ans; 
    }
};