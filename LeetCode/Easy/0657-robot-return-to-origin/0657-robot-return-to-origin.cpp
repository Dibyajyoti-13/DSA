class Solution {
public:
    bool judgeCircle(string moves) {
        int result = 0;
        for(char ch : moves){
            if(ch == 'U') result += 10;
            else if(ch == 'D') result -= 10;
            else if(ch == 'L') result -= 1;
            else if(ch == 'R') result += 1;
        }

        return result == 0;
    }
};