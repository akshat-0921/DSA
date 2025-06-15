class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> left,right;
        int count = 0;
        int mod = 1e9+7;

        for(auto num : nums)
        {
            right[num]++;
        }

        for(int i=0;i<n;i++)
        {
            int curr = nums[i];
            right[curr]--;

            int lc = left[2*curr];
            int rc = right[2*curr];

            count = (count + (1LL * lc * rc) % mod) % mod;

            left[curr]++;
        }

        return count%mod;
    }
};