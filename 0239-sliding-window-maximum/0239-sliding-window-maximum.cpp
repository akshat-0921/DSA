class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
            pq.push(nums[i]);
        }
        vector<int> ans;
        ans.push_back(pq.top());
        int l = 0, r = k;
        while (r < nums.size()) {
            mp[nums[l++]]--;
            mp[nums[r]]++;
            pq.push(nums[r++]);
            while (mp[pq.top()] == 0) pq.pop();
            ans.push_back(pq.top());
        }
        return ans;
    }
};