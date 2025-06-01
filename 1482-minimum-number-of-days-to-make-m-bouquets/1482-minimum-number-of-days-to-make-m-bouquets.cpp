class Solution {
private:
    bool check(int mid,vector<int>& bd, int m, int k)
    {
        int n=bd.size();
        int cnt=0,ans=0;
        for(int i=0;i<bd.size();i++)
        {
            if(bd[i]<=mid) cnt++;
            else cnt=0;
            if(cnt==k) 
            {
                cnt=0;
                ans++;
            }
        }
        return ans>=m;
    }
public:
    int minDays(vector<int>& bd, int m, int k) {
        int n=bd.size();
        long long temp=(long long)m*k;
        if(temp>n) return -1;
        int low=*min_element(bd.begin(),bd.end()),high=*max_element(bd.begin(),bd.end());
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,bd,m,k))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};