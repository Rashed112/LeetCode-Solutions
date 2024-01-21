class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), farthest, cnt=0;
        int l=0, r=0;
        while(r<n-1){
            farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest, i+nums[i]);
            }
            l = r+1;
            r = farthest;
            cnt++;
        }
        return cnt;
    }
};
