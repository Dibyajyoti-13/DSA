class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int del = 0;
        int b_count = 0;

        for(char ch : s){
            if(ch == 'b') b_count++;
            else if(ch == 'a'){
                del = min(del + 1, b_count);
            }
        }
        return del;
    }
};