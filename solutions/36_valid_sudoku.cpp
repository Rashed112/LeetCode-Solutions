class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      //define 2D sets to store rows, cols, squares
        unordered_set<char>rows[9];
        unordered_set<char>cols[9];
        unordered_set<char>squares[9]; // we also numbered the squares and store it in this set
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c] != '.'){
                    char val = board[r][c];
                    int square_index = (r/3)*3 + c/3; //to calclate the index no of a square
                    if(rows[r].count(val) || cols[c].count(val) || squares[square_index].count(val)){
                        return false;
                    }
                    rows[r].insert(val);
                    cols[c].insert(val);
                    squares[square_index].insert(val);
                }
            }
        }
        return true;
    }
};
