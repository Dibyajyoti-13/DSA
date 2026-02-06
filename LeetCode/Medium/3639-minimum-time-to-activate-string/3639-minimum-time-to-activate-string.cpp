class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        long long total = 1LL * (n + 1) * n / 2;
        if(total < k) return -1;

        auto can = [&](int t){
            vector<bool> track(n, false);
            for(int i = 0; i <= t; i++){
                track[order[i]] = true;
            }

            long long invalid = 0, count = 0;
            for(int i = 0; i < n; i++){
                if(!track[i]) count++;
                else{
                    invalid += count * (count + 1) / 2;
                    count = 0;
                }
            }
            invalid += count *(count + 1) / 2;

            return total - invalid >= k;
        };

        int low = 0, high = n - 1, ans = -1;
        while(low <= high){
            int mid = (low + high)/2;

            if(can(mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};