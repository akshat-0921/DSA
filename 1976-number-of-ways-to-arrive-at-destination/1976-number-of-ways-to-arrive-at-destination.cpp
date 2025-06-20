class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> time(n, 1e12);
        vector<long long> cnt(n, 0);
        long long mod = 1e9+7;
        vector<vector<pair<long long, long long>>> adj(n);
        for(auto r: roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        cnt[0]=1;
        time[0]=0;
        while(!pq.empty()){
            auto [nodetime, node] = pq.top();
            pq.pop();            
            for(auto [nbr, edtime]:adj[node]){
                long long newtime = nodetime+edtime;
                if(newtime<time[nbr]){
                    time[nbr]=newtime;
                    cnt[nbr] = (cnt[node])%mod;
                    pq.push({newtime, nbr});
                }
                else if(newtime==time[nbr]){
                    cnt[nbr]= (cnt[nbr]+cnt[node])%mod;
                }
            }
        }

        return cnt[n-1]%mod;
    }
};