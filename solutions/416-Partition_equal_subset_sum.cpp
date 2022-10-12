/*
* we have to understand the subproblem, which is, "is it possible to make a certain sum from an array?"
* then it's a 0/1 knapsack problem, which is whether we can take a certain index or not for making the sum
*/
class Solution {
public:
    int dp[205][20005]; // reason for 20005 is length*num[i] range which is 200*100=20000
    bool func(int ind, int target, vector< int >& nums)
    {
    if(target == 0) return true;
    if(ind < 0 ) return false;
    if(dp[ind][target] != -1) return dp[ind][target];
    //not consider ind-th index
    bool isPossible = func(ind-1, target, nums);
    //consider ind-th index
    if(target - nums[ind] >=0)
        isPossible |= func(ind-1, target-nums[ind], nums); //the reason to use 'or' is if any of the option is true, then it's possible

    return dp[ind][target] = isPossible;
    }

    bool canPartition(vector<int>& nums) {
    memset(dp, -1, sizeof(dp));
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%2){
        return false;
    }  
    return func(nums.size()-1, sum/2, nums); 

    }
};
