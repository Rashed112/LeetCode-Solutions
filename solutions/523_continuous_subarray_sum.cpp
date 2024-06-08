class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0, remainder = 0;
        unordered_map<int, int>m;
        m[0]=-1;
        for(int i = 0;i<nums.size();i++){
            prefix += nums[i];
            remainder = prefix % k;
            if(m.find(remainder)!=m.end()){
                if(i-m[remainder]>1){
                    return true;
                }
            }
            else{
                m[remainder] = i;
            }
        }
        return false;
    }
};
