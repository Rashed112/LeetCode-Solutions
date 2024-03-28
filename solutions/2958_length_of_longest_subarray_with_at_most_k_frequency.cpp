// variable size sliding window

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int l=0, r=0, len = 0;
        while(r<nums.size()){
            m[nums[r]]++;
            if(m[nums[r]]<=k){
                len = max(len, r-l+1);
                r++;
            }
            else if(m[nums[r]]>k){
                while(m[nums[r]]>k){
                    m[nums[l]]--;
                    l++;
                }
                r++;                
            }
        }
        return len;
    }
};
