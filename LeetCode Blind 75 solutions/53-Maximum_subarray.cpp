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

/*Solution-2: using dp */
/* here we'll store all the max sum in of subarray in the dp array. we'll go from first and decide whether (this index value) is larger or (this index value + previous index value)
is larger..and then the max value of dp array will be the ans of the summation of max subarray*/

typedef long long int ll;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        if(n == 0) return 0;
        ll dp[n+5];
        dp[0] = nums[0];
        for(int i = 1; i < size(nums); i++) 
            dp[i] = max((ll)nums[i], (ll)nums[i] + dp[i-1]);        
        return *max_element(dp, dp+n); /*using max_element we can find an iterator pointer of largest value of the array/vector, so by using '*' before it, we can return the value*/
    }
};

/*Solution-3: using DP-tabulation*/
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
