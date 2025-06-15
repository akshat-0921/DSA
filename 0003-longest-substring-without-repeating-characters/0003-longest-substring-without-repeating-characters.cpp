class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mpp;
        int n = s.size();
        int i = 0, ans = 0;

        for (int j = 0; j < n; ++j) {
            char ch = s[j];
            if (mpp.find(ch) != mpp.end() && mpp[ch] >= i) {
                i = mpp[ch] + 1;
            }
            mpp[ch] = j;
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
