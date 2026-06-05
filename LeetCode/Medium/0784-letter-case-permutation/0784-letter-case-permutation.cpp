class Solution {
public:
    vector<string> ans;

    void helper(string s, int idx){
        ans.push_back(s);

        if(idx >= s.size()) return;

        for(int i = idx; i < s.size(); i++){

            if(isalpha(s[i])){
                s[i]^=32;
                helper(s, i + 1);
                s[i]^=32;
            }
            
        }
    }

    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return ans;
    }
};