class Solution {
public:
    bool wordBreak(string s, vector<string> &dict) {
        if(dict.size()==0) return false;
        map<string,int> mpp;
        for(auto str:dict) mpp[str]++;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(mpp.find(word)!= mpp.end())
                    {
                        dp[i]=true;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};