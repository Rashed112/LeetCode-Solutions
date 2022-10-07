/*
Hints:  it's like sliding window problem...we simply calculate the sum from the first index, if the sum becomes less than zero, then we completely remove 
the previous part of the subarray and start to make a new subarray, as the negative ones won't help to make a subarray which will give largest sum
*/

/*Solution-1: using Kadane's Algorithm*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxSub = nums[0], curSum=0;

    for(int i=0;i<nums.size();++i){
        if(curSum<0) curSum=0;
        curSum +=nums[i];
        maxSub = max(maxSub, curSum);
    }
    return maxSub;

    }
};


/*Solution-2: using DP-tabulation*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        for(int i = 1; i < size(nums); i++) 
            dp[i] = max(nums[i], nums[i] + dp[i-1]);        
        return *max_element(begin(dp), end(dp)); /*using max_element we can find an iterator pointer of largest value of the vector, so 
                                                by using '*' before it, we can return the value*/
    }
};


/*link for understanding different types of solution: 
https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer
*/
