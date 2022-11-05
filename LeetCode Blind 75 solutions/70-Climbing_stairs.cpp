/*
* it's basically a fibonacci problem, if we simulate and observe some test cases..explanation:  ![](https://i.imgur.com/YEkxGyP.png)
![](https://i.imgur.com/goKgEHO.png)
*/

class Solution {
public:
    int dp[100];
    int fib(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=0) return dp[n];
        for(int i=3;i<=n;i++){
            dp[n]=fib(n-1)+fib(n-2);    
        }
        return dp[n];
    }
    int climbStairs(int n){
        memset(dp, 0, sizeof(dp));
        return fib(n);
    }
};
