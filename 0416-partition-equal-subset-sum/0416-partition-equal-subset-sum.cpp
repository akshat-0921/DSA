class Solution {
public:
int8_t dp[201][10001] = {[0 ... 200] = {[0 ... 10000] = -1}};
    int f(int tar,int i,vector<int>& nums)
    {
        if(tar==0) return true;
        if(i<0||tar<0) return false;
        bool take=false,ntake=false;
        if(dp[i][tar]!=-1) return dp[i][tar];
        take=f(tar-nums[i],i-1,nums);
        ntake=f(tar,i-1,nums);
        return dp[i][tar]=take|ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        return f(sum/2,n-1,nums);
    }
};