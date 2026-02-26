class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<list<int>> adjList(n);
        
        for(auto i : prerequisites){
            int u = i[0];
            int v = i[1];
            
            adjList[v].push_back(u);
        }
        
        vector<int> indeg(n, 0);
        for(auto i : prerequisites){
            indeg[i[0]]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i < n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(int neighbour : adjList[node]){
                indeg[neighbour]--;
                if(indeg[neighbour] == 0) q.push(neighbour);
            }
        }
        if(result.size() != n) return {};
        return result;
    }
};