class Solution {
public:
    long long primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int max_val = n ? *max_element(nums.begin(), nums.end()) : 0;

        vector<bool> prime(max_val + 1, true);
        if (max_val >= 0) prime[0] = false;
        if (max_val >= 1) prime[1] = false;
        for (int p = 2; p * p <= max_val; ++p) {
            if (!prime[p]) continue;
            for (int x = p * p; x <= max_val; x += p)
                prime[x] = false;
        }

        vector<pair<int, int>> prime_vals;
        for (int i = 0; i < n; ++i)
            if (prime[nums[i]])
                prime_vals.emplace_back(i, nums[i]);

        int total = prime_vals.size();
        if (total < 2) return 0;

        vector<long long> left(total), right(total), prefix(total + 1, 0);
        for (int i = 0; i < total; ++i) {
            int pos = prime_vals[i].first;
            int start = (i > 0 ? prime_vals[i - 1].first + 1 : 0);
            left[i] = pos - start + 1;
        }
        for (int i = 0; i < total; ++i) {
            int pos = prime_vals[i].first;
            int end = (i + 1 < total ? prime_vals[i + 1].first - 1 : n - 1);
            right[i] = end - pos + 1;
        }
        for (int i = 0; i < total; ++i)
            prefix[i + 1] = prefix[i] + left[i];

        long long result = 0;
        int l = 0;
        for (int r = 0; r < total; ++r) {
            while (l < r) {
                int max_val = prime_vals[l].second, min_val = prime_vals[l].second;
                for (int i = l; i <= r; ++i) {
                    max_val = max(max_val, prime_vals[i].second);
                    min_val = min(min_val, prime_vals[i].second);
                }
                if (max_val - min_val <= k) break;
                ++l;
            }

            if (r > l) {
                long long left_sum = prefix[r] - prefix[l];
                result += left_sum * right[r];
            }
        }

        return result;
    }
};
