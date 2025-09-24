bool comp1(vector<int>& v1,vector<int>& v2){
    return v1[2]<=v2[2];
}

bool comp2(pair<vector<int>,int>& p1 , pair<vector<int>,int>& p2){
    return p1.first[2]<=p2.first[2];
}

class Disjoint_set{
    vector<int> par;
    vector<int> size;
    public:
    Disjoint_set(int n){
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int findUpar(int node){
        if(par[node]==node) return node;
        return par[node]=findUpar(par[node]);
    }

    void unionbysize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);

        if(pu==pv) return ;
        else if(size[pu]<size[pv]){
            par[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            par[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge, vector<vector<int>>& queries) {
        sort(edge.begin(),edge.end(),comp1);
        
        vector<pair<vector<int>,int>> v;

        for(int i=0;i<q.size();i++){
            v.push_back({q[i],i});
        }

        sort(v.begin(),v.end(),comp2);

        vector<bool> ans(v.size());

        int idx=0;

        Disjoint_set ds(n);
        for(int i=0;i<v.size();i++){

            int limit=v[i].first[2];
            int node1=v[i].first[0];
            int node2=v[i].first[1];
            int idx_query=v[i].second;

            while(idx<edge.size()){
                if(edge[idx][2]<limit){
                    ds.unionbysize(edge[idx][0],edge[idx][1]);
                    idx++;
                }
                else{
                    break;
                }
            }
            if(ds.findUpar(node1)==ds.findUpar(node2)){
                ans[idx_query]=true;
            }
            else{
                ans[idx_query]=false;
            }
        }
        return ans;
    }
};