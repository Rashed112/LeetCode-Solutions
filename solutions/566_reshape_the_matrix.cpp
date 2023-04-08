class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(), n=mat[0].size();
        if(m*n != r*c){
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        int k=0, l=0;
        for(int i=0;i<r*c;i++){
            res[i/c][i%c] = mat[i/n][i%n];
        }
        return res;
    }
};
