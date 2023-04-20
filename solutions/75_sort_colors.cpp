class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0, r=nums.size()-1, i=0;
        while(i<=r){
            int temp;
            if(nums[i]==0){
                temp=nums[i];
                nums[i]=nums[l];
                nums[l]=temp;
                l++;
            }
            if(nums[i]==2){
                temp=nums[i];
                nums[i]=nums[r];
                nums[r]=temp;
                r--;
                i--;// i had to decrement to check the current position again, if it falls in any of our two cases
            }
            i++;
            
        }
    }
};
