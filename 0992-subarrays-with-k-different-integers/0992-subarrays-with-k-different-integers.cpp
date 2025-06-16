class Solution {
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, count = 0;
        map<int, int> freq;

        for (int right = 0; right < n; right++) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
            count += (right - left + 1);
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
