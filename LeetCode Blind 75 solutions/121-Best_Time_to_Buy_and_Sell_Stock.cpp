/*
* use of two pointers method
* if we use hashmap firstly to store indices in another loop, it'll be TLE
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=0, j=1; j<prices.size();  ){
           if(prices[j]-prices[i] >=0){
               ans = max(ans, prices[j]-prices[i]);
               j++;
           }
            else{
                i=j;
                j=i+1;
            }
            
        }
        return ans;     
        
    }
};

//Time Complexity: O(n)
//Space complexity: O(1)
