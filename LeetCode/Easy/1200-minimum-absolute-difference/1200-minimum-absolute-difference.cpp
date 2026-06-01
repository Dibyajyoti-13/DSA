class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        int diff = INT_MAX;

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i - 1] < diff){
                diff = arr[i] - arr[i - 1];
                result.clear();
                result.push_back({arr[i - 1], arr[i]});
            }
        
            else if(arr[i] - arr[i - 1] == diff) result.push_back({arr[i - 1], arr[i]});
        }
        return result;
    }
};