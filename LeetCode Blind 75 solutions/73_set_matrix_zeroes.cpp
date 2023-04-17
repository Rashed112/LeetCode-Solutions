class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(), c=matrix[0].size();
        bool rowZero = false; //this is the single 1 extra space had to use to identify whether we have to change 0th row or not
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){ //making 0th col/row to zero to identify which row/column we have to change
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    if(i>0){
                        matrix[i][0]=0;
                    }
                    else{
                        rowZero = true; //only for 0th row
                    } 
                }
            }
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0] == 0){//we must have to first check it, if we've to change the columnZero
            for(int i=0;i<r;i++){
                matrix[i][0]=0;
            }
        }
        if(rowZero){//then have to change rowZero
            for(int i=0;i<c;i++){
                matrix[0][i]=0;
            }
        }
    }
};
