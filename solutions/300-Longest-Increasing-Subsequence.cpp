/*
* sub-array is continous set of an array. sub-sequence is series of numbers of the array, but must have to be in order of the main array. e.g. let’s say an array, A={2, 6, 3, 9, 23} , now subarray could be {2, 6, 3}, {6, 3, 9} etc.. and sub-sequence could be {2, 3, 9}, {2, 6, 3} etc.
* have to think from the last position number where the sequence will end, and we'll change this last position of sequence and see which one have the largest sequence.
*/

class Solution {
public:
    
   int dp[2510];

    // dp top down approach
    int lis(int i, vector<int>& a){
        if(dp[i]!=-1) return dp[i];
        int ans = 1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                ans = max(ans, lis(j, a)+1);
                //cout<<ans;
            }
        }

        return dp[i]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
         memset(dp, -1, sizeof(dp));
        //to find max sub sequence for every position number
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans, lis(i, nums));
        }
        return ans;
    }
};
