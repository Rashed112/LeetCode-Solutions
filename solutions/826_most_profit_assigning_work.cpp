// Approach-1: using sorting
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>>v(profit.size());
        for(int i=0;i<profit.size();i++){
            v[i] = {difficulty[i], profit[i]};
        }
        int res = 0, j=0, maxProfit = 0;
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        for(int i=0;i<worker.size();i++){
            while(j<v.size() && v[j].first<=worker[i]){
                maxProfit = max(maxProfit, v[j].second);
                j++;
            }
            res+=maxProfit;
        }
        
        return res;
    }
};
// Time: O(nlogn+mlogm)
// Space: O(n)

// Approach-2: using memoization by tracking the max profit
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxDiff = *max_element(worker.begin(), worker.end());
        vector<int>v(maxDiff+1, 0);
        for(int i=0;i<difficulty.size();i++){
            // as I don't need info on byeond max difficulty a worker can handle
            if(difficulty[i]<=maxDiff){
                v[difficulty[i]] = max(v[difficulty[i]], profit[i]);
            }
        }
    
        int currMax = v[0];
        for(int i=1;i<v.size();i++){
            currMax=max(currMax, v[i]);
            v[i]=currMax;
        }
   
        int res = 0;
        for(int i=0;i<worker.size();i++){
            res+=v[worker[i]];
        }
        return res;
    }
};
// Time: O(maxDifficultyOfAWroker)
// Space: O(maxDifficultyOfAWroker)
