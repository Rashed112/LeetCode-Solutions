class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, res = 0;
        while(l<=r){
            int m = l + (r-l)/2;  // to avoid overflow
            if(pow(m, 2)>x){
                r = m-1;
            }
            else if (pow(m, 2) < x){
                l = m+1;
                res = m;
            }
            else return m;
        }
        return res;
    }
};
