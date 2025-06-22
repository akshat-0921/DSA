class Solution {
public:
    int cnt(const vector<int>& pos, int s) {
        int ans = 0;
        for (int i = 0; i < pos.size(); ++i) {
            ans += abs(pos[i] - (s + 2 * i));
        }
        return ans;
    }

    int minSwaps(vector<int>& a) {
        vector<int> e, o;
        for (int i = 0; i < a.size(); ++i) {
            (a[i] % 2 == 0) ? e.push_back(i) : o.push_back(i);
        }

        int n = a.size(), ec = e.size(), oc = o.size();
        if (abs(ec - oc) > 1) return -1;

        int res = INT_MAX;
        if (ec >= oc) res = min(res, cnt(e, 0));
        if (oc >= ec) res = min(res, cnt(o, 0));
        return res;
    }
};
