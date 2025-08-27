class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,string s1,string s2,vector<vector<int>>& dp)
    {
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp)); 
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size(),m=t2.size();vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(t1[i-1]==t2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};