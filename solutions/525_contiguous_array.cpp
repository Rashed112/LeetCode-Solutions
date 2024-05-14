class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>m;
        int n = nums.size(), sum = 0, maxL=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum--;
            }
            else{
                sum++;
            }
            m[0]=-1; // for the first prefix sum = 0
            if(m.find(sum)!=m.end()){
                maxL = max(maxL, i-m[sum]);
            }
            else{
                m[sum]=i;
            }
        }
        
        return maxL;
    }
};
