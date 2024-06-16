class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int reach = 1, added = 0, i=0;
        while(reach<=n){
            if(i<nums.size() && nums[i]<=reach){
                reach += nums[i++];
            }
            else{
                reach += reach;
                added++;
            }
        }
        return added;
    }
};
