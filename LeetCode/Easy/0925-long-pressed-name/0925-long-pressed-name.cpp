class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        for(int j = 0; j < typed.size(); j++){
            if(i < name.size() && name[i] == typed[j]) i++;
            else if(i > 0 && name[i - 1] == typed[j]) continue;
            else return false;
        }
        if(i != name.size()) return false;
        return true;
    }
};