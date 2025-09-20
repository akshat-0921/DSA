class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> mat(n);
        vector<int> indegree(n,0);vector<int> topo;
        for(int i=0;i<pre.size();i++)
        {
            indegree[pre[i][0]]++;
            mat[pre[i][1]].push_back(pre[i][0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:mat[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        // reverse(topo.begin(),topo.end());
        return topo.size()==n?topo:vector<int>();
    }
};