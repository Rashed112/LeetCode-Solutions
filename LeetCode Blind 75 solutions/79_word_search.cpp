class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, int curr, string &word ){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[curr]){
            return false;
        }
        
        if(curr == word.size()-1){
            return true;
        }
        //mark as visited
        board[i][j] = '#';
        
        bool found = dfs(i, j+1, board, curr+1, word ) |
                    dfs(i, j-1, board, curr+1, word )|
                    dfs(i+1, j, board, curr+1, word )|
                    dfs(i-1, j, board, curr+1, word );

        //change the character back for other searches //backtracking//
        board[i][j]=word[curr];

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size(); i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(i, j, board, 0, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//Time: O(n*m*4^l)
//Space: O(n*m)
