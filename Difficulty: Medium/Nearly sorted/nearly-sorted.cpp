class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i : arr) pq.push(i);
        
        while(!pq.empty()){
            arr[n++] = pq.top();
            pq.pop();
        }
    }
};