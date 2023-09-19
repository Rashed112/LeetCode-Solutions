class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
    
        for(auto x: nums){
            int temp = abs(x);
            if(nums[temp]<0){
                return temp;
            }
            nums[temp]=-nums[temp];
        }
        return -1;
    }
};
