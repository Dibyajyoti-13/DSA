class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunk = 0;
        //create right min
        vector<int> right_min(n + 1, INT_MAX);
        for(int i = n - 1; i >= 0; i--){
            right_min[i] = min(arr[i], right_min[i + 1]);
        }

        //calculate chunks
        int max = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > max) max = arr[i];
            if(max <= right_min[i+1]) chunk++;
        }
        return chunk;
    }
};