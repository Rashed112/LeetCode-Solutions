class Solution {
public:
    int dp[205][205];
    int dfs(int i, int j,int prevVal, vector<vector<int>>& matrix ){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()) return 0;

        if(matrix[i][j] <= prevVal) return 0;

        if(dp[i][j] !=0) return dp[i][j];

        int res = 1+ max({dfs(i, j+1, matrix[i][j], matrix),
                            dfs(i, j-1, matrix[i][j], matrix),
                            dfs(i+1, j, matrix[i][j], matrix),
                            dfs(i-1, j, matrix[i][j], matrix) });

        dp[i][j] = res;

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp, 0, sizeof(dp));
        int maxPath = 0;
        for(int i=0;i<matrix.size(); i++){
            for(int j=0;j<matrix[i].size(); j++){
                //if(dp[i][j] == 0)
                    maxPath =max(maxPath, dfs(i, j, -1, matrix));
            }
        }
        return maxPath;
    }
};
