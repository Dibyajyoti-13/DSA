class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> result = {-100000, 100000};

        int high = INT_MIN;
        for(int i = 0; i < k ; i++){
            pq.push({nums[i][0], i, 0});
            high = max(high, nums[i][0]);
        }

        while(true){
            auto top = pq.top();
            int low = top[0];

            if(high - low < result[1] - result[0]){
                result[0] = low;
                result[1] = high;
            }

            if(top[2] + 1 >= nums[top[1]].size()) break;
            pq.pop();
            pq.push({nums[top[1]][top[2] + 1], top[1], top[2] + 1});
            high = max(nums[top[1]][top[2] + 1], high);
        }
        return result;
    }
};