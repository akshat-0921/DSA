class Solution {
public:
    void merge(vector<int> &nums, int low, int high, int mid, int &count){
        int i=low;
        int j=mid+1;
        for(;i<=mid;i++)
        {
            while(j<=high&&nums[i]>2*(long)nums[j])
            {
                j++;
            }
            count+=(j-(mid+1));
        }
        i=low;
        j=mid+1;
        int ind=0;
        vector<int> result(high-low+1);
        while(i<=mid&&j<=high)
        {
            if(nums[i]<nums[j])
            {
                result[ind++]=nums[i];
                i++;
            }
            else 
            {
                result[ind++]=nums[j];
                j++;
            }
        }
        while(i<=mid)
        {
            result[ind++]=nums[i++];
        }
        while(j<=high)
        {
            result[ind++]=nums[j++];
        }
        ind=0;
        for(i=low; i<=high; i++){
            nums[i] = result[ind++];
        }
        return;
    }
    
    
    void mergeSort(vector<int>& nums,int low,int high,int& count)
    {
        if(low>=high) return;
        int mid=low+((high-low)/2);
        mergeSort(nums,low,mid,count);
        mergeSort(nums,mid+1,high,count);
        merge(nums,low,high,mid,count);
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        mergeSort(nums, 0, n-1, count);
        return count;
    }
};