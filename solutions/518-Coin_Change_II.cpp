/*
* dp (or memoization) is used when there is a always changing variable/argument in the recursion, if there is two argument like that, than it is 2D dp,
  here *ind* and amount both are changing, so it's 2D dp.
*/

class Solution {
public:
    int dp[310][10010];
    /*int func(int amount, vector<int>& coins){
        if(amount==0 ) return 1;
        if(dp[amount]!= -1) return dp[amount];

        int ways=0;
        for(int coin : coins){
            if(amount-coin >= 0){
                ways += func(amount-coin, coins); 
            }

        }
        return ways;
        //return dp[amount] = ans;
    }
    */
    /*## in this way there would be some cases where same way but different order like solutions({1,2,1,1}, {1,1,1,2} will treat differently 
    in coinChange-1 approach) will count both times...but in coinChange-2 problem we have to find no of unique combinations where order doesn't 
    matter({1,2,1,1}, {1,1,1,2} will treat as same in coinChange-2 problem)###*/
  
    /*###so, to avoid this problem, we have to use all the same coin first using multiple times in the same level branch of tree, then have to use 
    next coin using multiple times (1st level branches: root amount->1, 1*2, 1*3 etc, then 2nd level branches:1-> 2, 2*2, 2*3 etc, 1*2->2, 2*2, 2*3
    etc, 1*3->2, 2*2, 2*3 etc); where in previous coinchange problem's solution, we used 1st level branches: root amount->1,2,3 etc; 2nd level 
    branches: 1->1, 2, 3 etc, 2->1, 2, 3etc, 3->1, 2, 3 etc. So we have to understand this slight differerence of approach in recursion/tree.###*/

    int func1(int ind, int amount, vector< int >& coins)
    {
        if(amount == 0) return 1;
        if(ind<0) return 0; //even if we check this condition before amount, the ans will be wrong as after completeing a loop using n-th index coin, even if we got to make amount==0, we won't be incrementing our ways, rather we'll just send 0
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int ways=0;
        for(int coin_amount=0;  coin_amount<=amount; coin_amount+=coins[ind]){
            ways += func1(ind-1, amount-coin_amount, coins); //this func1(ind, amount) call is basically saying is it possible to make the expected amount using nth index coin
        }
        return dp[ind][amount]=ways;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return func1(coins.size()-1,amount, coins);
    }
};
