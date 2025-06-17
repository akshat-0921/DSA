class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2) 
                q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        if (fresh==0) return 0;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        int cnt=-1;
        while(!q.empty())
        {
            auto sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]==1) 
                    {
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                    }
                }
            }
            cnt++;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return cnt;
    }
};