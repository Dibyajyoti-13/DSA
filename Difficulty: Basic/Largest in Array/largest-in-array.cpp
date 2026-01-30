class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int max = INT_MIN;
        for(int i : arr){
            max = (max > i) ? max : i;
        }
        return max;
    }
};
