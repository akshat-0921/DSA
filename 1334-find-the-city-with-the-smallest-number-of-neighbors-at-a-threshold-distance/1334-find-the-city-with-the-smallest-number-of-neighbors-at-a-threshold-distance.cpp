class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++)
        {
            for(auto it:edges)
            {
                dist[it[0]][it[1]]=it[2];
                dist[it[1]][it[0]]=it[2];
            }
        }
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==1e8||dist[k][j]==1e8) continue;
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= k)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;
    }
};