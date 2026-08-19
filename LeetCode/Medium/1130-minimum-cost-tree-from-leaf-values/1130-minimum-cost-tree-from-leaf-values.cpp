class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int sum = 0;
        stack<int> st;

        st.push(INT_MAX);

        for(int x : arr) {
            while(st.top() <= x) {
                int mid = st.top();
                st.pop();

                sum += mid * min(st.top(), x);
            }

            st.push(x);
        }

        while(st.size() > 2) {
            int x = st.top();
            st.pop();

            sum += x * st.top();
        }

        return sum;
    }
};