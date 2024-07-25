class Solution {
public:
    void outPlaceMerge(vector<int>&nums, int low, int mid, int high){
        if(low>=high) return;
        int l = low, r = mid+1, i = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while(l <= mid && r<=high){
            sorted[i++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        }
        while(l<=mid){
            sorted[i++] = nums[l++];
        }
        while(r<=high){
            sorted[i++] = nums[r++];
        }
        for(i = 0; i < size; i++){
            nums[i + low] = sorted[i];
        }

    }

    void mergeSort(vector<int>&nums, int low, int high){
        if(low >= high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        outPlaceMerge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};

// Time: O(nlogn)
// Space: O(n)
