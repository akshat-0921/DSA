class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {

        int n = nums.size();
        
        int m = swaps.size();

        vector<vector<int>> adj(n);

        for(int i=0;i<m;i++){
            adj[swaps[i][0]].push_back(swaps[i][1]);
            adj[swaps[i][1]].push_back(swaps[i][0]);
        }

        long long ans = 0;

        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                
                vector<int> x; 
                int odd = 0;

                x.push_back(nums[i]);
                if((i%2) != 0){
                    odd++;
                }
                vis[i] = true;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto j: adj[node]){
                        if(!vis[j]){
                            vis[j] = true;
                            x.push_back(nums[j]);
                            if((j%2) != 0){
                                odd++;
                            }

                            q.push(j);
                        }
                    }
                }
                sort(x.begin(),x.end());
                for(int j=0;j<x.size();j++){
                    
                    if(odd > 0){
                        ans -= (long long)(x[j]);
                        odd--;
                    }else{
                        ans+= (long long)(x[j]);
                    }
                }
                
                
            }
            
        }

        return ans;
    }
};