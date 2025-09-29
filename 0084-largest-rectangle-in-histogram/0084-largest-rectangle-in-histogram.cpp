class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> stk;
        arr.push_back(0);
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty()&&arr[stk.top()]>arr[i])
            {
                int temp=stk.top();
                stk.pop();
                int nse=i;int pse=stk.empty()?-1:stk.top();
                ans=max(ans,(nse-pse-1)*arr[temp]);
            }
            stk.push(i);
        }
        return ans;
    }
};