//Solution-1:
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

//Solution-2: 
class Solution {
public:
    int dp[50];
    int rec(int n){//level
        if(n==0){
            return 1;
        }
        if(dp[n]!=0){
            return dp[n];
        }
        int ans=0;
        //choices
        for(int i=1;i<=2;i++){
            //check
            if(n-i>=0){
                //move
                int ways = rec(n-i);
                ans+=ways;
                dp[n]=ans;
            }
        }
        return ans;
    }
    int climbStairs(int n){
        memset(dp, 0, sizeof(dp));
        return rec(n);
    }
};
