using ll=long long;
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        ll ans=0;
        int n=prices.size();
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(k+1,vector<ll>(3,LLONG_MIN)));
        for(int i=0;i<=k;i++){
            dp[0][i][0]=0;
            dp[0][i][1]=-prices[0];
            dp[0][i][2]=+prices[0];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j][0]=dp[i-1][j][0];
                if(j+1<=k && dp[i-1][j+1][1]!=INT_MIN){
                    dp[i][j][0]=max(dp[i][j][0],dp[i-1][j+1][1]+prices[i]);
                }
                if(j+1<=k && dp[i-1][j+1][2]!=INT_MIN){
                    dp[i][j][0]=max(dp[i][j][0],dp[i-1][j+1][2]-prices[i]);
                }

                dp[i][j][1]=dp[i-1][j][1];
                if(dp[i-1][j][0]!=INT_MIN){
                    dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][0]-prices[i]);
                }

                dp[i][j][2]=dp[i-1][j][2];
                if(dp[i-1][j][0]!=INT_MIN){
                    dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][0]+prices[i]);
                }
            }
        }
        for(int j=0;j<=k;j++){
            ans=max(ans,dp[n-1][j][0]);
        }
        return ans;
    }
};