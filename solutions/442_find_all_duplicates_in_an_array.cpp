// Approach-1:
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int>m;
        for(auto val : nums){
            if(m.find(val)!=m.end()){
                res.push_back(val);
            }
            m[val]++;
        }
        return res;
    }
};

// Approach-2:
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            int idx = abs(nums[i]);
            if(nums[idx-1]<0){
                res.push_back(idx);
            }
            nums[idx-1] = -nums[idx-1];
        }
        return res;
    }
};
