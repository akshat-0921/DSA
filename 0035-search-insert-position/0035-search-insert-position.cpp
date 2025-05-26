class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int li = 0;
        int ri = nums.size()-1;

        while(li <= ri){
            int mid = li + (ri - li)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) li = mid + 1;
            else ri = mid - 1;
        }
        return li;

    }
};