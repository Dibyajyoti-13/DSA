class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void helper(int start, int end, int window){
        if(window == temp.size()){
            result.push_back(temp);
            return;
        }

        for(int i = start; i <= end; i++){
            temp.push_back(i);
            helper(i + 1, end, window);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        helper(1, n, k);
        return result;
    }
};