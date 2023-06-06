// Monotonic Decreasing Stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //pair: {index, temp}
        stack<pair<int, int>>sp;
        int n = temperatures.size();
        vector<int>res(n, 0);
        for(int i=0;i<n;i++){
            int currDay = i, currTemp = temperatures[i];  

            while(!sp.empty() && sp.top().second<currTemp){
                int prevDay = sp.top().first;
                sp.pop();
                res[prevDay]=currDay - prevDay;
            }
            sp.push({currDay, currTemp});
        }
        return res;
    }
};

//Time: O(n)
//Space: O(n)
