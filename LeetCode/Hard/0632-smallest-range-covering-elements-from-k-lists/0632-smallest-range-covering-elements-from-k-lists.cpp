class Solution {
public:
    struct Node {
        int val, list, idx;
        Node(int v, int l, int i) : val(v), list(l), idx(i) {}
    };

    struct cmp {
        bool operator()(const Node &a, const Node &b) const {
            return a.val > b.val;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<Node, vector<Node>, cmp> pq;

        vector<int> result = {-100000, 100000};
        int high = INT_MIN;

        for(int i = 0; i < k; i++){
            pq.emplace(nums[i][0], i, 0);
            high = max(high, nums[i][0]);
        }

        while(!pq.empty()){
            Node top = pq.top();
            pq.pop();

            int low = top.val;

            if(high - low < result[1] - result[0]){
                result = {low, high};
            }

            if(top.idx + 1 >= nums[top.list].size())
                break;

            int nextVal = nums[top.list][top.idx + 1];

            pq.emplace(nextVal, top.list, top.idx + 1);
            high = max(high, nextVal);
        }

        return result;
    }
};