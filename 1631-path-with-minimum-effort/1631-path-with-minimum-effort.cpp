class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
     int m;
     int n;

    bool isSafe(int row,int col){
        if(row>=0 && col>=0 && row<m && col<n ){
            return true;
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
         m=heights.size();
        n=heights[0].size();

        vector<vector<int>> helper(m,vector<int>(n,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        helper[0][0]=0;

        while(!pq.empty()){
            int val=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;

            pq.pop();

            for(int i=0;i<4;i++){
                int row=u+dir[i][0];
                int col=v+dir[i][1];

                if(isSafe(row,col)){
                    int diff=abs(heights[u][v]-heights[row][col]);
                    int maxi=max(diff,val);

                    if(maxi<helper[row][col]){
                        helper[row][col]=maxi;
                        pq.push({maxi,{row,col}});
                    }

                }
            }

        }

        return helper[m-1][n-1];
    }
};