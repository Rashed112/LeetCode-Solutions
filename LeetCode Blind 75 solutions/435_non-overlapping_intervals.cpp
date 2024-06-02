class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1){
            return 0;
        }
       sort(intervals.begin(), intervals.end());
       int res = 0, i=0;
       while(i<n-1){
            if(intervals[i][1]>intervals[i+1][0]){
                if(intervals[i+1][1]>intervals[i][1]){
                    intervals[i+1] = intervals[i];
                }
                res++;
            }
            i++;
       }

       return res; 
    }
};
