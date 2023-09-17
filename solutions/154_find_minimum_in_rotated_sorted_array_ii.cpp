class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r = nums.size()-1, res = nums[0];
        while(r-l>1){
            int m = l+(r-l)/2;
            if(nums[m]>nums[r]){
                l = m+1;
            }
            else if(nums[m]<nums[r]){
                r = m;
            }
            else{
                r--;
            }
        }
        if(nums[l]<=nums[r]){
            return nums[l];
        }
        else{
            return nums[r];
        }
    }
};
