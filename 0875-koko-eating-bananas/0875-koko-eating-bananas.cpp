class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max1 = *max_element(piles.begin(), piles.end());
        int l = 1, r = max1, mid;
        
        while (l <= r) {
            mid = (l + r) / 2;
            long long ans = 0;
            for (int x : piles) {
                ans += (x + mid - 1) / mid;
            }
            if (ans > h) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};