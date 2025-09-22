class DSU{
    unordered_map<char,char> parent;
    unordered_map<char,int> size;
    public:
        DSU(){
            for(int i=0;i<26;i++)
            {
                parent['a'+i]='a'+i;
                size['a'+i]=1;
            }
        }

        char findpar(char u)
        {
            if(parent[u]==u) return u;
            return parent[u]=findpar(parent[u]);
        }

        void unionbysize(char u,char v)
        {
            char upar=findpar(u);
            char vpar=findpar(v);

            if(u==v) return;

            if(size[upar]>size[vpar])
            {
                parent[vpar]=upar;
                size[upar]+=size[vpar];
            }

            else{
                parent[upar]=vpar;
                size[vpar]+=size[upar];
            }
        }

        bool contains(char u)
        {
            return parent.find(u)!=parent.end();
        }

};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU equal;
        for(auto it:equations)
        {
            if(it[1]=='=') equal.unionbysize(it[0],it[3]);
        }
        for(auto it:equations)
        {
            if(it[1]=='!') 
            {
                if(equal.contains(it[0])&&equal.contains(it[3])) return false;
            }
        }
        return true;
    }
};