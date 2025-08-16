class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(10,1);
        for(int i=1;i<10;i++){
            dp[i]=dp[i-1]*i;
        }
        vector<int>ans(10);
        ans[0]=1;
        for(int i=1;i<10;i++){
            ans[i]=9*(dp[9]/dp[10-i]);
            ans[i]+=ans[i-1];
        }
        return ans[n];
    }
};