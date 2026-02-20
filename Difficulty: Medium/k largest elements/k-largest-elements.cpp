class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        vector<int> result;
        
        priority_queue<int> pq;
        for(int i : arr) pq.push(i);
        
        while(k--){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};