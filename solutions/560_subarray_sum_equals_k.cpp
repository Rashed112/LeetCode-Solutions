class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0){
            return 0;
        }
        int r = 0, sum = 0, count = 0;
        unordered_map<int, int> m;
        while(r<nums.size()){
            sum+=nums[r];
            
            if(sum==k){
                count++;
            }
            if(m.find(sum-k) != m.end()){
                count+=m[sum-k];
            }
            
            m[sum]++;
            r++;
            
        }
        return count;
    }
};
