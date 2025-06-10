class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            auto it = hash.find(x[i]);
            if (it == hash.end()) {
                hash[x[i]] = y[i];
            } else {
                it->second = max(it->second, y[i]);
            }
        }

        if (hash.size() < 3) return -1;
        vector<int> vals;
        for (auto it : hash) {
            vals.push_back(it.second);
        }

        sort(vals.begin(), vals.end(), greater<int>());
        return vals[0] + vals[1] + vals[2];
    }
};