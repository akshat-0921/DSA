class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        for(int i=0;i<2*n;i++)
        {
            v.push_back(nums[i%n]);
        }
        vector<int> ans(2*n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=v[i])
            {
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(v[i]);
        }
        vector<int> res;
        for(int i=0;i<n;i++) res.push_back(ans[i]);
        return res;
    }
};