class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxi;
        deque<int> mini; int maxlen=0;
        int l=0,r=0; int n=nums.size();
        while(l<n and r<n){
            while(!maxi.empty() and maxi.back()<nums[r]) maxi.pop_back();
            maxi.push_back(nums[r]);
            while(!mini.empty() and mini.back()>nums[r]) mini.pop_back();
            mini.push_back(nums[r]);
            while(maxi.front()-mini.front()>limit){
                if(maxi.front()==nums[l]) maxi.pop_front();
                if(mini.front()==nums[l]) mini.pop_front();
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
        
    }
};