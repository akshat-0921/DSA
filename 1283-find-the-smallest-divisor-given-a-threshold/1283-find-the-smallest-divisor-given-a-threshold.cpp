class Solution {
private:
    bool check(int mid,vector<int>& nums,int t)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=(nums[i]/mid);
            if(nums[i]%mid!=0) ans++;
        }
        return ans<=t;
    }
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid,nums,t)) 
            {
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};