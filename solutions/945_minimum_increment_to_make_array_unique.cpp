// Solution - 1 : Using built-in sort
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                res+=1+nums[i-1]-nums[i];
                nums[i]=nums[i-1]+1;
            }
        }
        return res;
    }
};

// Solution - 2 : Using counting sort
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0, n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int>v(maxVal+n+1);
        for(auto x : nums){
            v[x]++;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]>1){
                int extra = v[i]-1;
                v[i+1] += extra; 
                res += extra;
            }
        }

        return res;
    }
};
