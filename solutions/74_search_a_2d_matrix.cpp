/*
Tricks to remember:
A n * m matrix converted into an array: matrix[x][y] : a[x * m + y]
An array can be converted into n * m matrix: a[x] : matrix[x / m][x % m]
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(), col=matrix[0].size();
        int l=0, r=row*col-1;//treating whole matrix as a sorted list
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target == matrix[mid/col][mid%col]){
                return true;
            }
            else if(target>matrix[mid/col][mid%col]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return false;

    }
};
