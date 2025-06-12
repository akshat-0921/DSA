class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int left=0,right=n-1;
        int top=0,down=n-1;
        int temp=1;
        while(top<=down&&left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                ans[top][i]=temp;
                temp++;
            }
            top++;
            for(int i=top;i<=down;i++)
            {
                ans[i][right]=temp;
                temp++;
            }
            right--;
            for(int i=right;i>=left;i--)
            {
                ans[down][i]=temp;
                temp++;
            }
            down--;
            for(int i=down;i>=top;i--)
            {
                ans[i][left]=temp;
                temp++;
            }
            left++;
        }
        return ans;
    }
};