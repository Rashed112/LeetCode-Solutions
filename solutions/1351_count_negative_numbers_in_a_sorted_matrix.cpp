class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        int total = r*c;
        int cnt=0;
        for(int i=0;i<total;i++){
            if(grid[i/c][i%c]<0){
                cnt++;
            }
        }
        return cnt;
    }
};
