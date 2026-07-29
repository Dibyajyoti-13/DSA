class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = -1;
        int c = 0;
        
        for(int i = 0; i < arr.size(); i++){
            int count = 0;
            
            for(int j = 0; j < arr[0].size(); j++){
                if(arr[i][j] == 1) count++;
            }
            
            if(count > c){
                c = count;
                ans = i;
            }
            
        }
        return ans;
    }
};