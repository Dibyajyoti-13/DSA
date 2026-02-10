class Solution {
public:
    bool isValid(string s) {
        stack<char> bucket;
        for(char ch : s){
            if(ch == '{' || ch == '(' || ch == '[') bucket.push(ch);
            else if(ch == '}' || ch == ']' || ch == ')'){
                if(bucket.empty()) return false;

                if(ch =='}' && bucket.top() == '{') bucket.pop();
                else if(ch ==']' && bucket.top() == '[') bucket.pop();
                else if(ch ==')' && bucket.top() == '(') bucket.pop();
                else return false;
            }
        }
        if(bucket.empty()) return true;
        return false;
    }
};