class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for(int i = 1; i < n - 1; i++){
            if(arr[i] > arr[i+1] && arr[i - 1] < arr[i]){
                int left = i;
                int right = i;

                while(left > 0 && arr[left - 1] < arr[left]) left--;
                while(right < n - 1 && arr[right] > arr[right + 1]) right++;
                count = max(count, right - left + 1);
            }
        }
        return count;
    }
};