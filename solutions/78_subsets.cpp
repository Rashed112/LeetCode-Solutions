class Solution {
public:
    vector<vector<int>>allSubsets;
    void generate(vector<int>&subset, int i, vector<int>&nums){
        if(i==nums.size()){
            allSubsets.push_back(subset);
            return;
        }
        //ith element not in subset
        generate(subset, i+1, nums);

        //ith element in subset
        subset.push_back(nums[i]);
        generate(subset, i+1, nums);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        generate(subset,0, nums);
        return allSubsets;
    }
};
//Time: O(N*(2^N))
//Space: O(N*(2^N))
