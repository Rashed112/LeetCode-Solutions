class Solution {
public:
    int helper(int i, int total, vector<int>&nums){
        if(i==nums.size()){
            return total;
        }
        return helper(i+1, total^nums[i], nums) + helper(i+1, total, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(0, 0, nums);

    }
};

// Time: O(2^n)
// Space: O(n)
