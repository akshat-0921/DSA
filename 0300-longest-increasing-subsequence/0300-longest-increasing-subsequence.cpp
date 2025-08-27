class Solution {
public:
    int f(int i,int j,vector<int>& nums,int n,vector<vector<int>>& dp)
    {
        if(i==n) return 0;
        int take=0,ntake=0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        if(j==-1||nums[i]>nums[j]) take=1+f(i+1,i,nums,n,dp);
        ntake=f(i+1,j,nums,n,dp);
        return dp[i][j+1]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,-1,nums,nums.size(),dp);
    }
};