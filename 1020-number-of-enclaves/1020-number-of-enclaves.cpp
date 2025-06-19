class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
            {
                vis[i][0]=1;
                q.push({i,0});
            }
            if(grid[i][n-1]==1)
            {
                vis[i][n-1]=1;
                q.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[0][i]==1)
            {
                vis[0][i]=1;
                q.push({0,i});
            }
            if(grid[m-1][i]==1)
            {
                vis[m-1][i]=1;
                q.push({m-1,i});
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]==1&&!vis[nx][ny])
                {
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};