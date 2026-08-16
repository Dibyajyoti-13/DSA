class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int ans = arr[0] + arr[1];
        for(int i = 0; i < arr.size() - 1; i++){
            int ele = arr[i] + arr[i + 1];
            ans = max(ele, ans);
        }
        return ans;
    }
};