class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long> dp(n, 0);
        dp[0] = 1;

        vector<int> pointerToPrime(primes.size(), 0);

        for (int i = 1; i < n; i++) {
            long minUglyNum = LONG_MAX;

            for (int j = 0; j < primes.size(); j++) {
                minUglyNum = min(minUglyNum, primes[j] * dp[pointerToPrime[j]]);
            }

            dp[i] = minUglyNum;

            for (int j = 0; j < primes.size(); j++) {
                if (minUglyNum == primes[j] * dp[pointerToPrime[j]]) {
                    pointerToPrime[j]++;
                }
            }
        }

        return dp[n - 1];
    }
};