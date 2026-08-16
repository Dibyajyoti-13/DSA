class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack<int> st;
        int n = q.size();
        int i = 0;
        
        if(n < k) return q;
        
        while(!q.empty() && i < k){
            st.push(q.front());
            q.pop();
            i++;
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        for(; i < n; i++){    
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};