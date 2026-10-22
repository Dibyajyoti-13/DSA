class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> mp;
        int count = 0;

        for(string word : strs){
            string w = word;
            sort(w.begin(), w.end());
            
            if(mp.find(w) != mp.end()){
                result[mp[w]].push_back(word);
            }
            else{
                mp.insert({w ,count});
                result.push_back({word});
                count++;
            }
        }
        return result;
    }
};