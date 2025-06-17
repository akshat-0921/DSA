class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1) 
                {
                    q.push({i,j});
                    ans[i][j]=INT_MAX;
                }
            }
        }
        auto check=[&](int x,int y){
            return x>=0&&x<m&&y>=0&&y<n;
        };
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(check(nx,ny)&&mat[nx][ny]==0)
                {
                    ans[x][y]=1;
                }
                else if(check(nx,ny)&&ans[x][y]+1<ans[nx][ny])
                {
                    q.push({nx,ny});
                    ans[nx][ny]=1+ans[x][y];
                }
            }
        }
        return ans;
    }
};