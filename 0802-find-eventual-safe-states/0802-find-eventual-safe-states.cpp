class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> mat(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                mat[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:mat[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};