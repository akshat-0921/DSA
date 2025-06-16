class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int sz=tasks.size();
        int maxi=INT_MIN;
        for(auto &x:tasks){
            mp[x]++;
            maxi=max(maxi,mp[x]);
        }
        int ans=(maxi-1)*(n+1);
        for(auto &x:mp){
            if(x.second==maxi){
                ans++;
            }
        }
        ans=max(ans,sz);
        return ans;
    }
};