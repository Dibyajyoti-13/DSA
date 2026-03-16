class Solution {
public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0; 
        
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                count++;
            }
        }
        
        if (count <= 1) return 0;
        
        int bad = 0;
        for (int i = 0; i < count; i++) {
            if (arr[i] > k) {
                bad++;
            }
        }
        
        int min_swaps = bad;
        
        for (int i = 0, j = count; j < n; i++, j++) {
            
            if (arr[i] > k) {
                bad--;
            }
            
            if (arr[j] > k) {
                bad++;
            }
            
            min_swaps = min(min_swaps, bad);
        }
        
        return min_swaps;
    }
};