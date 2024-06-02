class Solution {
public:
    int countSubstrings(string s) {
        int l = 0, r = 0, n = s.size(), res = 0;
        for(int i=0;i<n;i++){
            // odd length
            l=i;
            r=i;
            while(l>=0 && r<n  && s[l]==s[r]){
                res++;
                l--;
                r++;
            }
            //even length
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                res++;
                l--;
                r++;
            }
        }
        return res; 
    }
};

// Time: O(n^2)
// Space: O(1)
