class Solution {
    int f(vector<int>& nums, int i,vector<int>& dp)
    {
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+f(nums,i+2,dp);
        int ntake=f(nums,i+1,dp);
        return dp[i]=max(take,ntake);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};