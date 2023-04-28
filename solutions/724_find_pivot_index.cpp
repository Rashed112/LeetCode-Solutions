class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int ls=0, rs=0;
        for(int i=0;i<n;i++){
            if(i>0){
                ls+=nums[i-1];
            }
            rs = sum-ls-nums[i];
            if(ls==rs){
                return i;
            }
        }
        return -1;
    }
};
