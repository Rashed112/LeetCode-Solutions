class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1){
            return 1;
        }
        sort(points.begin(), points.end());
        long long int i=0, res = 0;
        while(i<n){
            int lastPoint = points[i][1];
            while(i<n-1 && lastPoint>=points[i+1][0]){
                lastPoint = min(lastPoint, points[i+1][1]);
                i++;
                
            }
            res++;
            i++;
        }
        return res;

    }
};
