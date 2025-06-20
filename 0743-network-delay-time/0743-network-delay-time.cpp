class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto i:times)adj[i[0]-1].push_back({i[1]-1, i[2]});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int> dist(n, INT_MAX);
        int a, b, ans=INT_MIN;
        dist[k-1]=0;
        pq.push({0, k-1});
        while(!pq.empty()){
            a=pq.top().first, b=pq.top().second;
            pq.pop();
            for(auto i:adj[b]){
                if(dist[i.first]>dist[b]+i.second) dist[i.first]=dist[b]+i.second, pq.push({dist[i.first], i.first});
            }
        }
        for(auto i:dist) ans=max(i, ans);
        return ans!=INT_MAX?ans:-1;
    }
};