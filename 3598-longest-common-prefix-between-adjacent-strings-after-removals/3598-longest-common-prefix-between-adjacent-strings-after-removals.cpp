class Solution {
    int getLongCommonPrefix(string& s1, string& s2){
        int len = 0;
        while(len < s1.size() && len < s2.size()){
            if(s1[len] == s2[len]) ++len;
            else break;
        }
        return len;
    }
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> res(n, 0);
        if(n <= 2) return res;
        vector<int> prefix;
        int biggest[3] = {0};
        for(int i=0; i<n-1; ++i){
            int len = getLongCommonPrefix(words[i], words[i+1]);
            prefix.push_back(len);
            if(len > biggest[0]){
                biggest[2] = biggest[1]; 
                biggest[1] = biggest[0]; 
                biggest[0] = len;
            } else if(len > biggest[1]) {
                biggest[2] = biggest[1]; 
                biggest[1] = len;
            } else if(len > biggest[2]){
                biggest[2] = len;
            }
        }
        res[0] = prefix[0] == biggest[0] ? biggest[1] : biggest[0];
        res[n-1] = prefix[n-2] == biggest[0] ? biggest[1] : biggest[0];
        for(int i=1; i<n-1; ++i){
            int maxLen = 0;
            int remove1 = prefix[i], remove2 = prefix[i-1];
            if(remove2 > remove1) swap(remove1, remove2);
            if(remove1 != biggest[0]){
                maxLen = biggest[0];
            } else if(remove2 != biggest[1]){
                maxLen = biggest[1];
            } else {
                maxLen = biggest[2];
            }
            res[i] = maxLen;
            res[i] = max(res[i], getLongCommonPrefix(words[i-1], words[i+1]));
        }
        return res;
    }
};