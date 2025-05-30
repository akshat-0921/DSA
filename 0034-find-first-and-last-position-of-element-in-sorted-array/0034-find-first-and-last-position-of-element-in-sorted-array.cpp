class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0,high=n-1;
        int left=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (nums[mid]==target) {
                left=mid;
                high=mid-1;
                continue;
            }
            if (nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        vector<int> ans(2,-1);
        int right=-1;
        if(left==-1) return ans;
        low=left,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (nums[mid]==target) {
                right=mid;
                low=mid+1;
                continue;
            }
            if (nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        ans[0]=left;
        ans[1]=right;
        return ans;
    }
};
