class Solution {
    public:
        void threeWayPartition(vector<int>& arr){
            int n = arr.size();
            int start = 0, end = n - 1;
            
            for(int i = 0; i <= end;){
                if(arr[i] == 0){
                    if(start == i){
                        start++;
                        i++;
                    }
                    else swap(arr[i], arr[start++]);
                }
                else if(arr[i] == 2){
                    swap(arr[i], arr[end--]);
                }
                else i++;
            }
        }
        
        void sort012(vector<int>& arr) {
            // code here
            threeWayPartition(arr);
        }
};