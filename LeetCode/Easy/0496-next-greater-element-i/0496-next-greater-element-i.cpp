class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){        
        unordered_map<int, int> mp;
        stack<int> st;

        for(int n : nums2){
            if(!st.empty() && st.top() < n){
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> result;
        for(int i : nums1){
            result.push_back(mp[i]);
        }
        return result;
    }
};