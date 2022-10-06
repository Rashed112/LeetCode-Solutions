class Solution {
public:
    int dp[38];
    int func(int n){
        if(n==0) return 0;
        if(n<=2) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = func(n-1)+func(n-2)+func(n-3);
        return dp[n];
    }
    
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return func(n);
    }
};
