class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> last(10, -1);
        int n = s.size();

        for(int i = 0; i < n; i++){
            last[s[i] - '0'] = i;
        }

        for(int i = 0; i < n; i++){
            for(int d = 9; d > s[i] - '0'; d--){
                if(last[d] > i){
                    swap(s[last[d]], s[i]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};