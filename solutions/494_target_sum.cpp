class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if((sum+target)%2!=0 || sum<abs(target)){
            return 0;
        }
        
        int targetSum = (target+sum)/2;
        
        vector<vector<int>>dp(n+1, vector<int>(targetSum+1, 0));

        for(int i=0;i<=n;i++){
            for(int j=0;j<=targetSum;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(i==0){
                    dp[i][j]=0;
                }
                else if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][targetSum];
    }
};
