class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int l = 0, r = 0, n = s.size();
        while(r<n){
            if(s[r]=='0'){
                res += (r-l);
                l++;
            }
            r++;
        }
        return res;
    }
};
