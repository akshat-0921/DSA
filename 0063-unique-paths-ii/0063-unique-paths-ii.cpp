class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if (mat[0][0] == 1 || mat[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};
