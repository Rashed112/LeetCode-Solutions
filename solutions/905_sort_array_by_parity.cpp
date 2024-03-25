class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r){
            if(nums[r]%2){
                r--;
            }
            else{
                swap(nums[l], nums[r]);
                l++;
            }

        }
        return nums;
    }
};
