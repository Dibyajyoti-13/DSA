class Solution {
  public:
    int prec(char c){
        if(c == '^') return 3;
        else if(c == '*' || c == '/') return 2;
        else if(c == '+' || c == '-') return 1;
        return -1;
    }
    
    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        string result = "";
        
        for(char ch : s){
            if(isalnum(ch)) result += ch;
            
            else if(ch == '(') st.push(ch);
            
            else if(ch ==')'){
                while(!st.empty() && st.top() != '('){
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else{
                while(!st.empty() && prec(st.top()) >= prec(ch) && !(ch == '^' && st.top() == '^')){
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};
