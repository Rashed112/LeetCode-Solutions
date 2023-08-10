// also known as Josephus problem

class Solution {
public:
    int solve(int n, int k){
        if(n==1){
            //n==1 means it's the 0-th node as for mod
            return 0;
        }
        return (solve(n-1, k)+k)%n; /* k was added as for every n, n-1 number of k traversal gets included for every cycle, and mod n was done to make the result under n*/
    }
    int findTheWinner(int n, int k) {
        return solve(n, k)+1; //as the calculation was on 0-indexed
    }
};

//Time: O(n)
//Space: O(n)
