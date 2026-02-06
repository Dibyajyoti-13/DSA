class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        long long total = 1LL * n * (n + 1) / 2;
        if (total < k) return -1;

        long long invalid = total;
        set<int> stars = {-1, n}; //boundaries

        for (int t = 0; t < n; t++) {
            int pos = order[t];

            auto it = stars.upper_bound(pos);
            int right = *it;
            int left = *prev(it);

            long long middle_lane = right - left - 1;
            long long right_lane = pos - left - 1;
            long long left_lane = right - pos - 1;

            invalid -= middle_lane * (middle_lane + 1) / 2;
            invalid += right_lane * (right_lane + 1) / 2;
            invalid += left_lane * (left_lane + 1) / 2;

            stars.insert(pos);

            if (total - invalid >= k)
                return t;
        }

        return -1;
    }
};