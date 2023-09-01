class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int l=0, r=n-1,i=n-1;
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                res[i]=pow(nums[l],2);
                l++;
                i--;
            }
            else{
                res[i]=pow(nums[r],2);
                r--;
                i--;
            }
        }
        return res;
    }
};
