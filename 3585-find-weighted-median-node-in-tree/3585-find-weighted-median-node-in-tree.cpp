typedef long long ll;
class Solution {
public:
    int n;
    int m;
    vector<vector<pair<int, int>>> es;
    vector<vector<pair<int, ll>>> dp;
    vector<pair<int, int>> parent;
    vector<int> depth;

    void dfs(int i, int p, int d, int w)
    {
        parent[i] = {p, w};
        depth[i] = d;
        d++;
        for (auto& [x, w] : es[i])
        {
            if (x == p) continue;
            dfs(x, i, d, w);
        }
    }

    int getlog(int n)
    {
        for (int i = 0; i <= 31; i++)
        {
            int b = 1 << i;
            if (b >= n)  return i;
        }
        return 31;
    }
    
    void build()
    {
        m = getlog(n);
        dp = vector<vector<pair<int, ll>>>(n, vector<pair<int, ll>>(m + 1));
        for (int i = 1; i < n; i++) dp[i][0] = parent[i];
        
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                int k = dp[i][j -1].first;
                ll w = dp[i][j -1].second;
                
                dp[i][j].first = dp[k][j - 1].first;
                dp[i][j].second = w + dp[k][j - 1].second; 
            }
        }
    }

    int jump(int x, int d, ll& wx)
    {
        for (int j = m; j >= 0; j--)
        {
            int b = 1 << j;
            if ((b & d) ==b) {
                wx += dp[x][j].second;
                x = dp[x][j].first;
            }
        }
        return x;
    }

    int lca(int x, int y, ll& wx, ll& wy)
    {
        int dx = depth[x];
        int dy = depth[y];
        if (dx < dy) return lca(y, x, wy, wx);
        x = jump(x, dx - dy, wx);
        if (x == y) return x;
        dx = dy;

        for (int j = m; j >= 0; j--)
        {
            if (dp[x][j].first != dp[y][j].first)
            {
                wx += dp[x][j].second;
                wy += dp[y][j].second;
                x = dp[x][j].first;
                y = dp[y][j].first;
            }
        }
        wx += dp[x][0].second;
        wy += dp[y][0].second;
        return dp[x][0].first;
    }
    int findL(int x, ll h)
    {
        if (h == 0) return x;
        for (int j = m; j >= 0; j--)
        {
            if (dp[x][j].second == h) return dp[x][j].first;
            else if (dp[x][j].second > h)
            {
                continue;
            }
            h -= dp[x][j].second;
            x = dp[x][j].first;
            return findL(x, h);
        }
        return x;
    }
    vector<int> findMedian(int n1, vector<vector<int>>& edges, vector<vector<int>>& qs) {
        n = n1;
        es.resize(n);
        for (auto& e : edges)
        {
            int x = e[0];
            int y = e[1];
            int w = e[2];
            es[x].push_back({y, w});
            es[y].push_back({x, w});
        }
        parent.resize(n);
        depth.resize(n);
        dfs(0, 0, 0, 0);
        build();
        vector<int> ans;
        for (auto& q : qs)
        {
            int x = q[0];
            int y = q[1];
            ll wx = 0;
            ll wy = 0;
            int c = lca(x, y, wx, wy);
            if (wx == wy || (wy + 1) == wx)
            {
                ans.push_back(c);
                continue;
            }
            ll d = wx + wy;
            if (wx > wy)
            {
                ll h = d - d / 2;
                int a = findL(x, h - 1);
                ans.push_back(parent[a].first);
                continue;
            }
            else 
            {
                
                ll h = d / 2;
                int a = findL(y, h);
                ans.push_back(a);
                continue;
            }
        }
        return ans;
    }
};