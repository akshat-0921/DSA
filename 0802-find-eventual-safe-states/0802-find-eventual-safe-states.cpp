class Solution {
private:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
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
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> mat(n);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                mat[it].push_back(i);
            }
        }
        return topologicalSort(mat);
    }
};