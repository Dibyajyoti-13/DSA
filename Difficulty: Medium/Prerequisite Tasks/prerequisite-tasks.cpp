class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        
        vector<vector<int>> adjList(N);
        for(auto i : prerequisites){
            int u = i.first;
            int v = i.second;
            adjList[v].push_back(u);
        }
        
        vector<int> indeg(N, 0);
        for(int i = 0; i < N; i++){
            for(auto j : adjList[i]){
                indeg[j]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(auto neighbour : adjList[node]){
                indeg[neighbour]--;
                
                if(indeg[neighbour] == 0) q.push(neighbour);
            }
        }
        
        if(result.size() != N) return false;
        return true;
    }
};