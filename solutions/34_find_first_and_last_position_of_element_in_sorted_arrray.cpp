class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        //first Binary Search- to find lower range
        int l=0, r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<target){
                l=m+1;
            }
            else{
                if(nums[m]==target){
                    res[0]=m;
                }
                r=m-1;
            }
        }
        //2nd Binary Search- to find higher range
        l=0, r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]>target){
                r=m-1;
            }
            else{
                if(nums[m]==target){
                    res[1]=m;
                }
                l=m+1;
            }
        }
        return res;
    }
};
