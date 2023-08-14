class Solution {
public:
    void combinations(vector<int>& candidates, int target, int sum, int start, vector<int>& currComb, vector<vector<int>>&res ){
        if(sum>target){
            return;
        }
        if(sum == target){
            res.push_back(currComb);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            currComb.push_back(candidates[i]);
            combinations(candidates, target, sum+candidates[i], i, currComb, res);
            currComb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>currComb;
        vector<vector<int>> res;
        combinations(candidates, target, 0, 0, currComb, res);
        return res;
    }
};

/*
Time: O(n^target)
Space: O(target)
*/
