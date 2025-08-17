class Solution {
public:
    bool f(int i,auto& nums,int& sum,auto& v)
    {
        if(i==nums.size())
        {
            for(int j=1;j<v.size();j++) if(v[j]!=v[j-1]) return false;
            return true;
        }
        unordered_map<int,int> mp;
        for(int j=0;j<v.size();j++)
        {
            if(v[j]+nums[i]<=sum and mp[v[j]]==0)
            {
                mp[v[j]]=1;
                v[j]+=nums[i];
                if(f(i+1,nums,sum,v)) return true;
                v[j]-=nums[i];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int n=nums.size(),sum=0;
        vector<int> v(k,0);
        for(auto i:nums) sum+=i;
        if(sum%k!=0) return 0;
        sum/=k;
        sort(nums.rbegin(),nums.rend());
        return f(0,nums,sum,v);
    }
};