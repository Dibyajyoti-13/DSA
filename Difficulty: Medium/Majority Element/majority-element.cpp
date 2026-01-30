class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        int n = arr.size();
        
        for(int i : arr){
            mp[i]++;
        }
        
        for(auto it: mp){
            if(it.second > n/2) return it.first;
        }
        return -1;
    }
};