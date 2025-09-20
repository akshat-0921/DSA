class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int right=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
        int left=right-1;
        vector<int> ans;
        while(left>=0||right<n)
        {
            if(left>=0&&right<n)
            {
                if(abs(nums[left])<abs(nums[right]))
                {
                    ans.push_back(nums[left]*nums[left]);
                    left--;
                }
                else
                {
                    ans.push_back(nums[right]*nums[right]);
                    right++;
                }
            }
            else if(left>=0) {ans.push_back(nums[left]*nums[left]);left--;}
            else  {ans.push_back(nums[right]*nums[right]);right++;}
        }
        return ans;
    }
};