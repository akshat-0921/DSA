class Solution {
public:
    string minWindow(string s, string t) {
        
        int ns = s.length();
        int nt = t.length();

        if(ns == 0 || nt == 0 || ns < nt) return "";

        unordered_map<char,int> mp;

        for(char ch: t) {
            mp[ch]++;
        }

        int i = 0;
        int j = 0;

        int ansLen = INT_MAX;
        int startIdx = -1;

        while(i < ns) {

            if(mp[s[i]] > 0) {
                nt--;
            }

            mp[s[i]]--;

            while(nt == 0) {

                if(i - j + 1 < ansLen) {
                    ansLen = i - j + 1;
                    startIdx = j;
                }

                mp[s[j]]++;

                if(mp[s[j]] > 0) {
                    nt++;
                } 

                j++;
            }

            i++;
        }

        return (ansLen == INT_MAX) ? "" : s.substr(startIdx, ansLen);
    }
};