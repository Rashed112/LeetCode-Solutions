// Solution-1: [Space Optimal, Operation Sub-Optimal]
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[j++]=nums[i];
            }
        }
        while(j<n){
            nums[j] = 0;
            j++;
        }
    }
};

// Solution-2: [Optimal]
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[j++], nums[i]); //zeroes will be sorted out at the end
            }
        }
    }
};
