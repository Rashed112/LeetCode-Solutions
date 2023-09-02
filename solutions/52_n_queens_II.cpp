class Solution {
public:
    int queen[10]; /*queen[i]-> where is my queen in row i*/
    bool check(int row, int col){
        for(int i=0;i<row;i++){
            int pRow = i;
            int pCol = queen[i];

            if(pCol == col || abs(pCol-col)==abs(pRow-row)){
                return 0;
            }
        }
        return 1;
    }
    int rec(int level, int n){/*no of ways to populate [level...n-1] rows for a valid configuration*/
        //level in which we are placing the queen
        //pruning

        //basecase
        if(level == n){
            return 1;
        }
        //compute
        int ans=0;
        //loop over all choices
        for(int col=0; col<n; col++){
            //check if the choice is valid
            if(check(level, col)){
                //place the queen
                queen[level] = col;
                //explore the options
                ans += rec(level+1, n);
                //revert placing the queen (backtrack)
                queen[level] = -1;
            }
        }
        return ans;

    }
    int totalNQueens(int n) {
        memset(queen, -1, sizeof(queen));
        return rec(0, n);
    }
};
