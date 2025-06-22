#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int n, t;
    vector<vector<int>> g;
    vector<int> in, out, flat, xorval;

    Tree(int size, vector<int>& val, vector<int>& par) {
        n = size;
        g.resize(n);
        in.resize(n);
        out.resize(n);
        flat.resize(n);
        xorval.resize(n);
        for (int i = 1; i < n; ++i)
            g[par[i]].push_back(i);
        xorval[0] = val[0];
        t = 0;
        dfs(0, -1, val);
    }

    void dfs(int u, int p, vector<int>& val) {
        in[u] = t;
        flat[t++] = xorval[u];
        for (int v : g[u]) {
            xorval[v] = xorval[u] ^ val[v];
            dfs(v, u, val);
        }
        out[u] = t;
    }
};

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int size) {
        n = size + 2;
        bit.assign(n, 0);
    }

    void upd(int i, int v) {
        for (++i; i < n; i += i & -i)
            bit[i] += v;
    }

    int sum(int i) {
        int res = 0;
        for (++i; i; i -= i & -i)
            res += bit[i];
        return res;
    }

    int find(int k) {
        int i = 0, s = 0;
        for (int j = 17; j >= 0; --j) {
            if (i + (1 << j) < n && s + bit[i + (1 << j)] < k) {
                i += 1 << j;
                s += bit[i];
            }
        }
        return i < n - 2 ? i : -1;
    }
};

class Solution {
public:
    vector<int> getXors(int n, vector<int>& val, vector<int>& par, vector<vector<int>>& q) {
        Tree tree(n, val, par);
        vector<int> all = tree.xorval;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        unordered_map<int, int> xtoid;
        for (int i = 0; i < all.size(); ++i)
            xtoid[all[i]] = i;

        int qn = q.size();
        int bsz = max(1, (int)sqrt(n));
        vector<tuple<int, int, int, int>> qs;

        for (int i = 0; i < qn; ++i) {
            int u = q[i][0], k = q[i][1];
            qs.emplace_back(tree.in[u] / bsz, tree.out[u], tree.in[u], i);
        }
        sort(qs.begin(), qs.end());

        Fenwick bit(all.size());
        vector<int> f(all.size(), 0), res(qn, -1);
        int l = 0, r = 0;

        auto add = [&](int i) {
            int x = tree.flat[i], j = xtoid[x];
            if (f[j]++ == 0) bit.upd(j, 1);
        };
        auto rem = [&](int i) {
            int x = tree.flat[i], j = xtoid[x];
            if (--f[j] == 0) bit.upd(j, -1);
        };

        for (auto [blk, qr, ql, id] : qs) {
            while (l < ql) rem(l++);
            while (l > ql) add(--l);
            while (r < qr) add(r++);
            while (r > qr) rem(--r);
            int k = q[id][1];
            int idx = bit.find(k);
            if (idx != -1) res[id] = all[idx];
        }
        return res;
    }
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        return getXors(vals.size(),vals,par,queries);
    }
};