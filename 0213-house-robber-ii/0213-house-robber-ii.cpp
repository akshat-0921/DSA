class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int r = nums[idx] + solve(idx-2, nums, dp);
        int nr = solve(idx-1, nums, dp);
        return dp[idx] = max(r, nr);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1(nums.begin(), nums.end()-1);
        vector<int> dp1(n, -1);
        int r1 = solve(n-2, temp1, dp1);
        vector<int> temp2(nums.begin()+1, nums.end());
        vector<int> dp2(n, -1);
        int r2 = solve(n-2, temp2, dp2);
        return max(r1, r2);
    }
};