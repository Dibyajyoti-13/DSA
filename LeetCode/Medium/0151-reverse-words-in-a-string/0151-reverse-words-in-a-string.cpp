class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string result = "";
        stack<string> st;

        for(char ch : s){
            if(ch != ' ') word += ch;
            else{
                if(word != "") st.push(word);
                word = "";
            }
        }
        if(word != "") st.push(word);

        while(!st.empty()){
            result += st.top();
            st.pop();
            if(!st.empty()) result += " ";
        }
        return result;
    }
};