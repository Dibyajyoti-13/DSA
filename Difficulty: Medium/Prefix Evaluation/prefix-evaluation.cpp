class Solution {
  public:
    int floorDiv(int a, int b) {
        if (a * b < 0 && a % b != 0)
            return (a / b) - 1;
        return a / b;
    }
    int evaluatePrefix(vector<string>& arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        for(int i = n - 1; i >= 0; i--){
            if(arr[i] == "*" || arr[i] =="/" || arr[i] == "+" || arr[i] == "-" || arr[i] == "^"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                
                if(arr[i] == "*") st.push(a*b);
                else if(arr[i] == "/") st.push(floorDiv(a, b));
                else if(arr[i] == "+") st.push(a + b);
                else if(arr[i] == "-") st.push(a - b);
                else st.push(pow(a, b));
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
        
    }
    
};