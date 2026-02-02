class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int need = k - 1;

        multiset<int> small, large;
        long long sumSmall = 0;
        long long ans = LLONG_MAX;

        auto add = [&](int x) {
            if (small.size() < need) {
                small.insert(x);
                sumSmall += x;
            } else if (!small.empty() && x < *small.rbegin()) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);

                small.insert(x);
                sumSmall += x;
            } else {
                large.insert(x);
            }
        };

        auto remove = [&](int x) {
            auto itSmall = small.find(x);
            if (itSmall != small.end()) {
                sumSmall -= x;
                small.erase(itSmall);

                if (!large.empty()) {
                    auto it = large.begin();
                    sumSmall += *it;
                    small.insert(*it);
                    large.erase(it);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        // initial window
        for (int i = 1; i <= dist + 1; i++) {
            add(nums[i]);
        }

        ans = sumSmall;

        // slide window
        for (int i = dist + 2; i < n; i++) {
            remove(nums[i - (dist + 1)]);
            add(nums[i]);
            ans = min(ans, sumSmall);
        }

        return nums[0] + ans;
    }
};
