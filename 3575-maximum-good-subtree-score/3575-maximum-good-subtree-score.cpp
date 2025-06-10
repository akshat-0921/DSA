class Solution {
public:
    static constexpr long long mod = 1000000007LL;
    long long solve(int i, int m, vector<pair<long long, int>> &p, vector<vector<long long>> &dp) {
        if (i >= (int)p.size()) {
            return 0;
        }

        if (dp[i][m] != -1) 
            return dp[i][m];

        long long ntk = solve(i + 1, m, p, dp);

        long long tk = 0;
        bool conflict = false;  
        int new_m = m;         

        for (int j = 0; j <= 9; j++) {
            if (((m >> j) & 1) && ((p[i].second >> j) & 1)) {
                conflict = true;
                break;
            }
            if (!((m >> j) & 1) && ((p[i].second >> j) & 1)) {
                new_m |= (1 << j);
            }
        }
        if (!conflict) {
            tk = (p[i].first + solve(i + 1, new_m, p, dp)) % mod;
        }
        return dp[i][m] = max(ntk, tk);
    }
    int get_mask(int v) {
        int new_m = 0;
        while (v) {
            int c = v % 10;
            if ((new_m >> c) & 1) 
                return -1;  
            new_m |= (1 << c);
            v /= 10;
        }
        return new_m;
    }
    vector<pair<long long, int>> dfs(int i, vector<int> &vals, unordered_map<int, vector<int>> &adj, long long &ans) {
        vector<pair<long long, int>> vp;
        for (auto it : adj[i]) {
            vector<pair<long long, int>> child_vp = dfs(it, vals, adj, ans);
            for (auto &pr : child_vp) {
                vp.push_back(pr);
            }
        }
        int msk = get_mask(vals[i]);
        if (msk != -1) {
            vp.push_back({vals[i], msk});
        }
        int sz = (1 << 10);
        vector<vector<long long>> dp((int)vp.size(), vector<long long>(sz, -1));
        long long maxi = solve(0, 0, vp, dp);
        ans = (ans + maxi) % mod;
        return vp;
    }
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < (int)par.size(); i++) {
            if (par[i] != -1) {
                adj[par[i]].push_back(i);
            }
        }

        long long ans = 0;
        dfs(0, vals, adj, ans);
        return (int)ans;
    }
};