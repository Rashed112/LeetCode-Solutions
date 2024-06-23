class Solution {
public:
    int atMost(vector<int>&nums, int goal){
        if(goal<0){
            return 0;
        }
        int l = 0, r = 0, res = 0, currSum = 0, n = nums.size();
        while(r<n){
            currSum += nums[r];
            while(currSum > goal){
                currSum -= nums[l++];
            }
            res += (r-l+1);
            r++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};
