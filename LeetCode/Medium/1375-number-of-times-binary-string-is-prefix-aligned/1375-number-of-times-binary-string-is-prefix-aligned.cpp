class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        long long sum = 0;
        int count = 0;
        for(int i = 0; i < flips.size(); i++){
            sum += flips[i];
            if(sum == ((i + 1)* 1ll * (i + 2) / 2)) count++;
        }
        return count;
    }
};