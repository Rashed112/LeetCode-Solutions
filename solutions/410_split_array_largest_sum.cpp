class Solution {
public:
    bool isPossible(vector<int>&nums, int k, int mid){
        int currSum = 0, cnt=1;
        for(int i=0;i<nums.size();i++){
            if(currSum+nums[i]<=mid){
                currSum+=nums[i];
            }
            else{
                cnt++;
                if(cnt>k || nums[i]>mid){
                    return false;
                }
                currSum = nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=nums[0], r=0;
        for(int i=0;i<nums.size();i++){
            r+=nums[i]; //maximum possible sum of a subarray
            l=max(l, nums[i]); //max of minimum possible sum of subarray
        }
        
        while(r-l>1){
            int m=l+(r-l)/2;
            if(isPossible(nums, k, m)){
                r=m;
            }
            else{
                l=m+1;
            }
            
        }
        if(isPossible(nums, k, l)){
            return l;
        }
        else{
            return r;
        }
    }
};

//Time: O(n*log(sum(nums))
//Space: O(1)
