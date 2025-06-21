class DSU{
    public:
    vector<int> rank,par;
    DSU(int n)
    {
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
    }
    int findpar(int u)
    {
        if(par[u]==u) return u;
        return par[u]=findpar(par[u]);
    }
    void unionRank(int u,int v)
    {
        int paru=findpar(u);
        int parv=findpar(v);
        if(paru==parv) return;
        if(rank[paru]<rank[parv])
        {
            par[paru]=parv;
        }
        else if(rank[paru]>rank[parv])
        {
            par[parv]=paru;
        }
        else {
            par[parv]=paru;
            rank[parv]++;
        }
    }
};
    class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e=connections.size();
        if(e<n-1) return -1;
        DSU dsu(n);
        for(auto edges:connections)
        {
            int a=edges[0];
            int b=edges[1];
            if(dsu.findpar(a)!=dsu.findpar(b))
            {
                dsu.unionRank(a,b);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(dsu.findpar(i)==i) cnt++;
        }
        return cnt-1;
    }
};