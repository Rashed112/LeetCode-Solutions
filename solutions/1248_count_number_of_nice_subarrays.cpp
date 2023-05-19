//sliding window

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l = 0, r, cnt=0, res=0;
        for(r=0;r<n;r++){
            if(nums[r] & 1){
                k--;
                cnt=0;
            }
            while(k==0){
                cnt++;
                k+=nums[l++] & 1;
            }
            res+=cnt;
        }
        return res;
    }
};
