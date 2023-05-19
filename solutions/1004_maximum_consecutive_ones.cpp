class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j, n=nums.size();
        for(j=0; j<n; j++){
            if(nums[j]==0){
                k--;
            }
            if(k<0 && nums[i++]==0){
                k++;
            }
        }
        return j-i;
    }
};
