// variable size sliding window, using 3 pointers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int l_near=0, l_far = 0, r=0, res = 0;
        while(r<nums.size()){
            m[nums[r]]++;
            
            while(m.size()>k){
                m[nums[l_near]]--;
                if(m[nums[l_near]]==0){
                    m.erase(nums[l_near]);
                }
                l_near++;
                l_far = l_near;
            }

            while(m[nums[l_near]]>1){
                m[nums[l_near]]--;
                l_near++;
            }

            if(m.size()==k){
                res += l_near-l_far+1;
            }
            r++;
        }   
        return res;
    }
};
