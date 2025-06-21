class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        dis[0][0]=grid[0][0];
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        auto check=[&](int x,int y){
            return x>=0&&y>=0&&x<n&&y<n;
        };
        while(!pq.empty())
        {
            auto [wt,it]=pq.top();
            int x=it.first;
            int y=it.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(check(nx,ny)&&grid[nx][ny]<dis[nx][ny])
                {
                    if(grid[nx][ny]>wt)
                    {
                        dis[nx][ny]=grid[nx][ny];
                        pq.push({dis[nx][ny],{nx,ny}});
                    }
                    else if(dis[nx][ny]>wt)
                    {
                        dis[nx][ny]=wt;
                        pq.push({dis[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dis[n-1][n-1];
    }
};