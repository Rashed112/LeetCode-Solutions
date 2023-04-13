class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1, r=num;
        while(l<=r){
            int m=l+(r-l)/2;
            if(pow(m,2)==num){
                return true;
            }
            else if(pow(m,2)<num){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return false;
    }
};
