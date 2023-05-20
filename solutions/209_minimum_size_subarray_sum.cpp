//two pointers

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r, sum=0, res=INT_MAX;
        for(r=0; r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                res = min(res, r-l+1);
                sum-=nums[l++];
            }
        }
        return res == INT_MAX? 0 : res;
    }
};
