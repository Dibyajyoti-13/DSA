class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //first check max and store index that dont follow for both
        //next check for the smaller new arr if yes return its size else the other one 
        //if both fails return -1
        int t = 0, b = 0, t_occ = 0, b_occ = 0;
        vector<int> t_freq(7, 0);
        for(int i : tops){
            t_freq[i]++;    
            if(t_freq[i] > t_occ){
                t_occ = t_freq[i];
                t = i;
            }
        }

        vector<int> b_freq(7, 0);
        for(int i : bottoms){
            b_freq[i]++;
            if(b_freq[i] > b_occ){
                b_occ = b_freq[i];
                b = i;
            }
        }

        vector<int> tx;
        vector<int> bx;

        for(int i = 0; i < tops.size(); i++){
            if(tops[i] != t) tx.push_back(i);
            if(bottoms[i] != b) bx.push_back(i);
        }

        bool b_ok = true, t_ok = true;

        for(int i = 0; i < tx.size(); i++){
            if(bottoms[tx[i]] != t){
                t_ok = false;
                break;
            }
        }

        for(int i = 0; i < bx.size(); i++){
            if(tops[bx[i]] != b){
                b_ok = false;
                break;
            }
        }

        if(t_ok && b_ok) return min(tx.size(), bx.size());
        else if(t_ok) return tx.size();
        else if(b_ok) return bx.size();
        else return -1;
    }
};