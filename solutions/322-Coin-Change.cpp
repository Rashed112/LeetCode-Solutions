/*
 * have to check substracting coins from the amount to see if we can get zero, if we can than that's our recursion 
*/


class Solution {
public:
    int dp[10010];
    int func(int amount, vector<int>& coins){
    if(amount==0 ) return 0;
    if(dp[amount]!= -1) return dp[amount];

    int ans = INT_MAX;
    for(int coin : coins){
        if(amount-coin >= 0){
            ans = min(ans+0LL, func(amount-coin, coins)+1LL); /*here LL is used in both argument as min can only compare same type of arg and this is used to overcome overflow when ans will use INT_MAX as its value*/
        }
    }
    return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = func(amount, coins);
        return ans == INT_MAX ? -1 : ans;
    }
};
