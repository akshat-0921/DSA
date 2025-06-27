class Solution {
public:
int f(int m,int n,vector<vector<int>>& dp)
{
    dp[0][0]=1;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0&&j==0) continue;
            int t1=0,t2=0;
            if(i>0) t1=dp[i-1][j];
            if(j>0) t2=dp[i][j-1];
            dp[i][j]=t1+t2;
        }
    }
    return dp[m][n];
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        return f(m-1,n-1,dp);
    }
};