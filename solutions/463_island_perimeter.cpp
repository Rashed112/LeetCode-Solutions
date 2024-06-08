class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, int &perimeter){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0){
            perimeter++;
            return;
        }
        if( grid[r][c]==2){
            return;
        }
        grid[r][c] = 2;
        
        dfs(r+1, c, grid, perimeter);
        dfs(r-1, c, grid, perimeter);
        dfs(r, c+1, grid, perimeter);
        dfs(r, c-1, grid, perimeter);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
       int perimeter=0;
       for(int r=0; r<grid.size();r++){
            for(int c=0; c<grid[r].size(); c++){
                if(grid[r][c]==1){
                    dfs(r, c, grid, perimeter);
                    break;
                }
            }
       }
       return perimeter;
    }
};
