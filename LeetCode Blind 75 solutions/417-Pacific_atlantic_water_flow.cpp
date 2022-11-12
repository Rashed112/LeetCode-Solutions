//##Very Very important for understanding the concept of dfs+dp and usage of 2D vector
/*
Explanation:
* this problem's trick is to understand where to run dfs and how to memoize it
* in this problem, we can run dfs only on the row and column which are directly in touch with pacific ocean and according to condition which 
  cell we can visit we will memoize it using a dp array(visited array) and in another array of dp(path array) we'll permantly store the path we are   
  travelling with an increment 1.
* then we'll run dfs only for the atlantic ocean touched row and column and also memozie it which path we are traveling (but we have to remember  
  that before running dfs in these cells , we have to initialize the visited array (dp array) by 0..and we'll also do increment on the parmanent path array..
* now in the path array(dp) in which cell, the acquired value is 2, that means from there we can go to both ocean.
* now just we have to collect and store the indices of the path array which are 2 in a 2D vector
*/

class Solution {
public:
   int dp[205][205]; //to check visited or not
    void dfs(int i, int j,int prevVal, vector<vector<int>>& heights, vector<vector<int>>& path){
        vector<int>v;
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size()) return;
        if(heights[i][j] < prevVal) return ;
        if(dp[i][j] != 0) return;
        path[i][j]++;
        dp[i][j]=1;

        dfs(i, j+1, heights[i][j], heights, path);
        dfs(i, j-1, heights[i][j], heights, path);
        dfs(i+1, j, heights[i][j], heights, path);
        dfs(i-1, j, heights[i][j], heights, path);


    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> path(205, vector<int>(205, 0)); //permanantly storing the visiting cell
        vector<vector<int>> ans;
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<heights.size(); i++){
            for(int j=0; j<heights[i].size(); j++){
                if(i==0 || j==0){
                    dfs(i, j, -1, heights, path);
                }         
            }
        }
        memset(dp, 0, sizeof(dp)); //initializing the dp array with 0 again
        for(int i=0;i<heights.size(); i++){
            for(int j=0; j<heights[i].size(); j++){
                if(i==heights.size()-1 || j==heights[0].size()-1){
                    dfs(i, j, -1, heights, path);
                }

            }
        }
        //storing the indices to a 2D vector
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                vector<int>v;
                if(path[i][j]==2){
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v); //if we put this line out of the if condition, there'll be stored some unnecessary null vector?
                }
                v.clear();

            }

        }

        return ans;

    }
};
