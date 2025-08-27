class Solution {
    int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp)
    {
        int n=nums.size();
        if(i==n) return 0;
        int take=0,ntake=0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        if(j==-1||nums[i]>nums[j]) take=1+f(i+1,i,nums,dp);
        ntake=f(i+1,j,nums,dp);
        return dp[i][j+1]=max(take,ntake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int ans=f(0,-1,nums,dp);
        return ans;
    }
};