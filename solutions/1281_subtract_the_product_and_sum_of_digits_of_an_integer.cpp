class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro = 1, sum = 0;
        while(n){
            pro *= n%10;
            sum+=n%10;
            n/=10;
        }
        return pro - sum;
    }
};
