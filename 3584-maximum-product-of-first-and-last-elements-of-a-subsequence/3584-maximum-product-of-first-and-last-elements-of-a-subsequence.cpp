long long maximumProduct(vector<int>& nums, int m) {
    long long mn = INT_MAX, mx = INT_MIN, res = LLONG_MIN;
    for (int i = 0; i < nums.size(); ++i)
        if (i + 1 >= m) {
            mn = min(mn, 1LL * nums[i + 1 - m]);
            mx = max(mx, 1LL * nums[i + 1 - m]);
            res = max({res, mn * nums[i], mx * nums[i]});
        }
    return res;
}