//Solution-1: 
//Time: O(nlogn), Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==1){
            return nums[0];
        }
        int i=0,res = 0;
        while(i<nums.size()-1){
            if(nums[i] == nums[i+1]){
                i+=2;
            }
            else{
                res = i;
                break;
            }
            if(i==nums.size()-1){
                res = i;
            }
        }
        return nums[res];    
    }
};

//Solution-2: Using Bitwise XOR operation 
//Time: O(n), Space: O(1)
class Solution {
public:
    /*
    XOR's properties,
    1. a^a=0
    2. a^b^a=b
    3. (a^a^b) = (b^a^a) = (a^b^a) = b 
    4. Similarly, a^a^a.... (even times)=0 and a^a^a....(odd times)=a
    */
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto x: nums){
            res^=x;
        } 
        return res;
    }
};
