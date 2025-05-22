class Solution {
private:
    int check(int mid,vector<int> nums)
    {
        int cnt=0;
        int curr=0;
        for (int i=0;i<nums.size();i++){
            if(curr+nums[i]<mid){
                curr+=nums[i];
            }
            else{
                cnt++;
                curr=nums[i];
            }
        }
        cnt++;
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        if(k==1) return sum;
        if(k==nums.size()) return maxi;
        int low=maxi;
        int high=sum;
        int ans=maxi;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,nums)>k){
                ans=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;
    }
};