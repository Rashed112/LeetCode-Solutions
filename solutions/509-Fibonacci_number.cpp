class Solution {
public:
    int dp[31];
    int func(int n) {
       
        if(n==0) return 0;
        if(n<=2) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = fib(n-1)+fib(n-2);
        return dp[n];
    }
    
    int fib(int n){
        memset(dp, -1, sizeof(dp));
        return func(n);
    }
};
