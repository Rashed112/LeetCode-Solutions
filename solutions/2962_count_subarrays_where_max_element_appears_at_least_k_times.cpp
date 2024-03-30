class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxE = *max_element(nums.begin(), nums.end());
        long long int l = 0, r = 0, cnt=0, res = 0;

        while(r<nums.size()){
            if(nums[r]==maxE){
                cnt++;
            }
            while(cnt==k){
                if(nums[l]==maxE){
                    cnt--;
                }
                l++;
            }
            res += l;
            r++;
        }
        return res;
    }
};
