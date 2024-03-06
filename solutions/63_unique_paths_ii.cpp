class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();
        if(obstacleGrid[r-1][c-1]==1 || obstacleGrid[0][0]==1){
            return 0;
        }
        vector<long long int>dp(c, 0);
        dp[c-1]=1;
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if(obstacleGrid[i][j] == 1){
                    dp[j]=0;
                }
                else if(j == c-1){
                    continue;
                }
                else if(obstacleGrid[i][j]==0){
                    dp[j] = dp[j]+dp[j+1];
                }
            }
        }
        return dp[0];
    }
};

// Time: O(r*c)
// Space: O(c)
