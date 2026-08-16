class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < arr.size(); i++) {

            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            if (arr[i] < 0)
                dq.push_back(i);

            if (i >= k - 1) {
                if (!dq.empty())
                    ans.push_back(arr[dq.front()]);
                else
                    ans.push_back(0);
            }
        }

        return ans;
    }
};