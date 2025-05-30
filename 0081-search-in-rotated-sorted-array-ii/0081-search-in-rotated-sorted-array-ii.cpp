class Solution {
public:
    bool search(vector<int>& nums, int tar) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==tar) return true;
            if(nums[mid]==nums[low]&&nums[mid]==nums[high]) 
            {
                high--;
                low++;
            }
            else if (nums[low] <= nums[mid]) {
                    if (nums[low] <= tar && tar < nums[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                else {
                    if (nums[mid] < tar && tar <= nums[high]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
        }
        return false;
    }
};