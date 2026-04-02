class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int m = 0;
        int last_pos = -1;

        for(int i = 0; i < n; i++){
            if(seats[i] == 1){
                if(last_pos == -1) m = i;
                else m = max(m, (i - last_pos) / 2);

                last_pos = i;
            }
        }
        m = max(m, (n - last_pos - 1));
        return m;
    }
};