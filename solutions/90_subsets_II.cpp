class Solution {
public:
    vector<vector<int>>allSubs;
    void generate(vector<int>&sub, int i, vector<int>&nums){
        if(i==nums.size()){
            allSubs.push_back(sub);
            return;
        }

        //all subsets that includes nums[i]
        sub.push_back(nums[i]);
        generate(sub, i+1, nums);
        sub.pop_back();

        //all subsets that doesn't include nums[i]
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        generate(sub, i+1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>sub;
        generate(sub, 0, nums);
        return allSubs;
    }
};
//Time: O(N*(2^N))
//Space: O(N*(2^N))
