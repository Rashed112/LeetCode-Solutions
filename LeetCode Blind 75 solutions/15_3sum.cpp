//Two Pointers

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>vv;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            int l=i+1, r=n-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    vv.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(nums[l]==nums[l-1] && l<r){
                        l++;
                    }
                }
                if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return vv;
    }
};
