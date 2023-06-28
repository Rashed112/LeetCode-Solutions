// very important to understand stack usage

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>>sp;
        for(int i=0;i<heights.size();i++){
            int start = i;
            while(!sp.empty() && sp.top().second > heights[i]){
                int index = sp.top().first;
                int w = i - index;
                int h = sp.top().second;
                res = max(res, w*h);
                sp.pop();
                start = index;
            }
            sp.push({start, heights[i]});
        }

        while(!sp.empty()){
            int w = heights.size() - sp.top().first;
            int h = sp.top().second;
            res = max(res, w*h);
            sp.pop();
        }
        return res;
    }
};

// time O(n)
// space O(n)
