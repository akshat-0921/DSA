class DSU
{
    unordered_map<int,int> parent,size;
    public:
        DSU(vector<int> nums){
            for(int i=0;i<nums.size();i++) 
            {
                parent[nums[i]]=nums[i];
                size[nums[i]]=1;
            }
        }

        bool contains(int x){
            return parent.find(x)!=parent.end();
        }

        int getsize(int x)
        {
            int par=findpar(x);
            return size[par];
        }

        int findpar(int u)
        {
            if(parent[u]==u) return u;
            return parent[u]=findpar(parent[u]);
        }

        void unionbysize(int u,int v)
        {
            int upar=findpar(u);
            int vpar=findpar(v);

            if(upar==vpar) return;

            if(upar>vpar){
                size[upar]+=size[vpar];
                parent[vpar]=upar;
            }

            else{
                size[vpar]+=size[upar];
                parent[upar]=vpar;
            }
        }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DSU dsu(nums);
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            if(dsu.contains(nums[i]-1)){
                dsu.unionbysize(nums[i],nums[i]-1);
            }
            if(dsu.contains(nums[i]+1)){
                dsu.unionbysize(nums[i],nums[i]+1);
            }
            ans=max(ans,dsu.getsize(nums[i]));
        }
        return ans;
    }
};