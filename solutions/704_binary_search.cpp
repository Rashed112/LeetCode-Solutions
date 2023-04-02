//Approach:-1 (Using normal Binary Search)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return -1;
    }
};

//Approach:-2 (using built in function)
class Solution {
public:
    int search(vector<int>& nums, int target) {
         // Find the insertion position `idx`.
        int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (idx > 0 && nums[idx - 1] == target) {
            return idx - 1;
        } else {
            return -1;
        }    
    }
};
