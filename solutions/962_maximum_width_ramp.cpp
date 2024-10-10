class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>mxr(n, 0);
        int maxV = 0;
        // preprocessing to store the max right value for each pos
        for(int i = n-1; i>=0;i--){
            maxV = max(nums[i], maxV);
            mxr[i]=max(maxV, nums[i]);
        }
        int res = 0, l = 0, r =1;
        while(l<=r && r<n){
            if(nums[l]<=mxr[r]){
                res= max(res, r-l);
                r++;
            }
            else{
                l++;
            }
        }  
        return res;
    }
};
