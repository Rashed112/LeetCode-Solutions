class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i=0, x, y;
        while(i<n){
            x = intervals[i][0];
            y = intervals[i][1];
            while(i+1<n && intervals[i+1][0]<=y){
                y = max(y, intervals[i+1][1]);
                i++;    
            }
            res.push_back({x, y});
            i++;

        }
        
        return res;
    }
};

// Time: O(n*logn)
// Space: O(n)
