class Solution {
public:
    int dp[100005][2];
    int f(vector<int>&nums1,vector<int>&nums2,int i,bool swap){
        if(i==nums1.size()) return 0;
        if(dp[i][swap]!=-1) return dp[i][swap];
        int ans = INT_MAX;
        if(i==0){
            ans = min(ans,f(nums1,nums2,i+1,false));
            ans = min(ans,1+f(nums1,nums2,i+1,true));
        }
        if(i!=0 and swap==false){
            if(nums1[i]>nums1[i-1] and nums2[i]>nums2[i-1]) ans = min(ans,f(nums1,nums2,i+1,false));
            if(nums2[i]>nums1[i-1] and nums1[i]>nums2[i-1]) ans = min(ans,1+f(nums1,nums2,i+1,true));
        }
        if(i!=0 and swap==true){
            if(nums1[i]>nums2[i-1] and nums2[i]>nums1[i-1]) ans = min(ans,f(nums1,nums2,i+1,false));
            if(nums2[i]>nums2[i-1] and nums1[i]>nums1[i-1]) ans = min(ans,1+f(nums1,nums2,i+1,true));
        }
        return dp[i][swap] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return f(nums1,nums2,0,false);
    }
};