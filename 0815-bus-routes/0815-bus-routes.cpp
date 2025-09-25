class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        map<int,vector<int>> mpp;
        for(int i=0;i<routes.size();i++)
        {
            for(auto it:routes[i])
            {
                mpp[it].push_back(i);
            }
        }
        vector<bool> vis(routes.size(),0);
        queue<int> q;
        for(auto it:mpp[source])
        {
            q.push(it);
            vis[it]=true;
        }

        int c=1;

        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto node=q.front();
                q.pop();
                for(auto it:routes[node])
                {
                    if(it==target) return c;
                    for(auto i:mpp[it])
                    {
                        if(vis[i]) continue;
                        vis[i]=1;
                        q.push(i);
                    }
                }
            }
            c++;
        }
        return -1;
    }
};