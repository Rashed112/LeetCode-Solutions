class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0, right=matrix[0].size()-1;
        int top=0, bottom=matrix.size()-1;
        vector<int>res;
        while(left<=right && top<=bottom){
            //top row
            for(int i=left; i<=right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;

            //right col
            for(int i=top; i<=bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            //bottom row
            if(top<=bottom){/*have to check it again for single row matrix*/
                for(int i=right;i>=left; i--){
                    res.push_back(matrix[bottom][i]);
                }
            }
            bottom--;

            //left col
            if(left<=right){/*hvae to check it again for signle col matrix*/
                for(int i=bottom; i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return res;
        
    }
};

//Time: O(row*col)
//Space: O(1)
