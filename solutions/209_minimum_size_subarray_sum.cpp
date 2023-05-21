//Solution-1: two pointers - O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r, sum=0, res=INT_MAX;
        for(r=0; r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                res = min(res, r-l+1);
                sum-=nums[l++];
            }
        }
        return res == INT_MAX? 0 : res;
    }
};

//Solution-2: Binary Search - O(nlog n)
class Solution {
    #define ll long long 
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int ans = INT_MAX;
        vector<int> sums(n+1, 0);
        for(int i=1;i<=n;i++){
            sums[i]= sums[i-1]+nums[i-1];
        }
        for(int i=0; i<n;i++){
            int find = target+sums[i];
            int idx = lower_bound(sums.begin(), sums.end(), find)- sums.begin();
            if(idx != n+1){
                ans = min(ans, idx-i);
            }
        }
        return ans == INT_MAX? 0 : ans;
    }
};
