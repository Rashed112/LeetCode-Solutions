class Solution {
public:
    int specialArray(vector<int>& nums) {
        unordered_map<int, int>ump;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }
        for(int i=0;i<=1000;i++){
            if(i==n){
                return i;
            }
            n-=ump[i];
        }
        return -1;
    }
};
