class Solution {
private:
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxA=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for (int c = 0; c < m; c++)
        {
            for (int r = 0; r < n; r++)
            {
                if (matrix[r][c] == '1')
                {
                    if (r != 0)
                        dp[r][c] = dp[r - 1][c] + 1;

                    else
                        dp[r][c] = 1;
                }
                else
                    dp[r][c] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            maxA=max(maxA,largestRectangleArea(dp[i]));
        }
        return maxA;
    }
};