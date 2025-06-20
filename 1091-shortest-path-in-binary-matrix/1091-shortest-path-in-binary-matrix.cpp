class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        pair<int,int> src={0,0};
        pair<int,int> dest={n-1,n-1};
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        while(!q.empty())
        {
            auto it=q.front();
            auto [x,y]=it.second;
            int dis=it.first;
            q.pop();
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nx=x+i;
                    int ny=y+j;
                    if(nx>=0&&ny>=0&&nx<n&&ny<n&&1+dis<dist[nx][ny]&&grid[nx][ny]==0)
                    {
                        q.push({1+dis,{nx,ny}});
                        dist[nx][ny]=1+dis;
                    }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};