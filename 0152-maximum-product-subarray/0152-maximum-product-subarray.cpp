class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int prod=1,temp=1;
        for(int i=0;i<n;i++)
        {
            prod=prod*nums[i];
            temp=temp*nums[i];
            if(prod>ans) 
            {
                ans=prod;
            }
            if(temp>ans) 
            {
                ans=temp;
                temp=1;
            }
        }
        return ans;
    }
};