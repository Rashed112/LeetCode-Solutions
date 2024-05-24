// Approach - 1: 
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


// Approach - 2 :
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums){
            sum += x;
        }
        if(sum%2){
            return false;
        }
        int target = sum/2, n = nums.size();
        int dp[n+1][target+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target; j++){
                if(j==0){
                    dp[i][j]=1;
                }
                else if(i==0){
                    dp[i][j]=0;
                }
                else if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};
