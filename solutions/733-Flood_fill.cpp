class Solution {
public:
    void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size(); //one row size = column size
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(image[i][j] != initialColor) return; //this condition is working the same as visited[] check

        image[i][j] = newColor;

        dfs(i-1, j, initialColor, newColor, image);
        dfs(i+1, j, initialColor, newColor, image);
        dfs(i, j-1, initialColor, newColor, image);
        dfs(i, j+1, initialColor, newColor, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(color != initialColor){
            dfs(sr, sc, initialColor, color, image);
        }
        return image;
    }
};
