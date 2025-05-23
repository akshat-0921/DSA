class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<long long> P(n+1, 0);
        for (int i = 0; i < n; i++)
            P[i+1] = P[i] + A[i];

        deque<int> dq;
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && P[i] - P[dq.front()] >= K) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && P[i] <= P[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};