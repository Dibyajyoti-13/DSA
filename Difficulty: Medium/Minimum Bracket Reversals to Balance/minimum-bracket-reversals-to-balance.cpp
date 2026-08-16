class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        if(s.size() & 1) return -1;
        stack<char> st;
        
        for(char ch : s){
            if(ch == '}'){
                if(!st.empty() && st.top() == '{') st.pop();
                else st.push(ch);
            }
            else st.push(ch);
        }
        
        int open = 0, close = 0;
        while(!st.empty()){
            if(st.top() == '{') open++;
            else close++;
            
            st.pop();
        }
        
        return (open + 1) / 2 + (close + 1) / 2;
    }
};