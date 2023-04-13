// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, r=n, m;
        while(l<=r){
            m=l+(r-l)/2;
            if(isBadVersion(m) == false){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return l;
    }
};
