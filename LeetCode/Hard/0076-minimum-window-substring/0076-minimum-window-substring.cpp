class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> mp;
        unordered_map<char, int> window;

        for(char str : t) mp[str]++;

        int req = mp.size();
        int formed = 0;
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {

            char c = s[right];
            window[c]++;

            if(mp.count(c) && window[c] == mp[c]) formed++;

            while(formed == req) {
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                window[ch]--;

                if(mp.count(ch) && window[ch] < mp[ch]) formed--;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};