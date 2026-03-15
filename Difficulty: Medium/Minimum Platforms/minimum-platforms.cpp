class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<pair<int, int>> train;
        for(int i = 0; i < arr.size(); i++){
            train.push_back({arr[i], dep[i]});
        }
        
        sort(train.begin(), train.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int ans = 0;
        
        for(int i = 0; i < train.size(); i++){
            while(!pq.empty() && pq.top() < train[i].first){
                pq.pop();            
            }
            
            pq.push(train[i].second);
            ans = max(ans, (int)pq.size());
        }
        return ans; 
    }
};
