class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            bitset<32>b(i);
            b.count();
            ans.push_back(b.count());
        }
        return ans;

    }
};