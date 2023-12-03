class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i=0;i<points.size()-1;i++){
            int pointX = points[i][0], pointY = points[i][1];
            int targetX = points[i+1][0], targetY = points[i+1][1];
            res += max(abs(targetX-pointX), abs(targetY-pointY));
        }
        return res;
    }
};
