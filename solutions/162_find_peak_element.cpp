//Solution-1: 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        //search in the remaining array
        int l=1, r=n-2;
        while(l<=r){
            int m= l+(r-l)/2;
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                return m;
            }
            else if(nums[m-1]>nums[m]){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return -1; //dummy return statement
    }
};

//Solution-2: 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=size(nums), l=0, r=n-1;
        while(l < r){ // l<=h when u are expecting to return from loop itself
            int m=(l+r) >> 1;
            if(nums[m+1] > nums[m])
                l = m+1;
            else
                r = m; //m is still part of selected subarray as m+1 is possible peak
        }
        return l; // returning r will also give the same ans here
    }
};
