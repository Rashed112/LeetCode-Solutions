class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid ){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        //if current position is already visited or of water
        if(grid[i][j] == '2' || grid[i][j]== '0') return ;  
        grid[i][j]='2'; //we can control if it's visited or not by changing the value of that position

        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size(); i++){
            for(int j=0;j<grid[i].size(); j++){
                //check if visited or not
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
