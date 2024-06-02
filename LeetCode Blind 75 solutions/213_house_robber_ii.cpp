class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int prev = 0, curr1 = 0, curr2 = 0, next = 0;
        for(int i=0;i<nums.size()-1;i++){
            next = max(prev+nums[i], curr1);
            prev = curr1;
            curr1 = next;
        }
        prev = 0, next = 0;
        for(int i=1;i<nums.size();i++){
            next = max(prev+nums[i], curr2);
            prev = curr2;
            curr2 = next;
        }
        return max(curr1, curr2);
    }
};
