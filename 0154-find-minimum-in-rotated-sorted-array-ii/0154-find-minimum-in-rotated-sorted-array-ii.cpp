class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1;
        int mini=INT_MAX;
        while(start<=end)
        {
            int mid=(start+end)/2;
            mini=min(mini,nums[mid]);
            if(nums[mid]==nums[start]) 
            {
                start++;;
                continue;
            }
            if(nums[mid]==nums[end]) 
            {
                end--;
                continue;
            }
            if(nums[mid]>nums[start])
            {
                mini=min(nums[start],mini);
                start=mid+1;
            }
            else 
            {
                end=mid-1;
            }
        }
        return mini;
    }
};