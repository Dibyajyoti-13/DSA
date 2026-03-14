class Solution {
public:
    int check(int target, vector<int> tops, vector<int> bottoms){
        int top_swap = 0, bottom_swap = 0;
        for(int i = 0; i < tops.size(); i++){
            if(tops[i] != target && bottoms[i] != target) return -1;

            if(tops[i] != target) top_swap++;
            if(bottoms[i] != target) bottom_swap++; 
        }
        return min(top_swap, bottom_swap);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //the fact that either ans is there or -1 => value that satisfies the condition can be either tops[0] or bottom[0] 
        int ans = check(tops[0], tops, bottoms);
        if(ans != -1) return ans;
        return check(bottoms[0], tops, bottoms);
    }
};