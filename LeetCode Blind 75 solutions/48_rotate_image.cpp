class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l=0, r=matrix.size()-1;
        while(l<r){
            //for n cells in a row, we have to do (n-1) rotations
            for(int i=0;i<(r-l);i++){
                int top = l, bottom = r, topleft;
                //save the topleft
                topleft = matrix[top][l+i];
                //move bottom left into top left
                matrix[top][l+i] = matrix[bottom-i][l];
                //move bottom right into bottom left
                matrix[bottom-i][l] = matrix[bottom][r-i];
                //move top right into bottom right
                matrix[bottom][r-i] = matrix[top+i][r];
                //move top left into top right
                matrix[top+i][r] = topleft;  
            }
            //for sub square matrix
            l++;
            r--;
        }
    }
};
