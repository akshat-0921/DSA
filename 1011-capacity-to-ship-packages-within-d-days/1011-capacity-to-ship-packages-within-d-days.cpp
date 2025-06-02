#include <numeric>
using namespace std;
class Solution {
private:
    bool check(int mid, vector<int> w, int days)
    {
        int cnt=1,sum=0;
        for(int i=0;i<w.size();i++)
        {
            if(sum+w[i]<=mid)
                sum+=w[i];
            else{ 
                sum=w[i];
                cnt++;
            }
        }
        return cnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid,weights,days)) 
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};