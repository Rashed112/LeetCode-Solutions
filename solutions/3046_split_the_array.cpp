class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int>m;
        for(auto x : nums){
            m[x]++;
            if(m[x]>2){
                return false;
            }
        }
        return true;

    }
};
