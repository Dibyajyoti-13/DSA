class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here.
        int probable_answer = -1;
        unordered_map<int, int> mp;
        int n = arr.size();
        for(int i = n - 1; i >= 0; i--){
            mp[arr[i]]++;
            if(mp[arr[i]] > 1) probable_answer = i + 1;
        }
        return probable_answer;
    }
};