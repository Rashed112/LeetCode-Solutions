class Solution {
public:
    string longestPalindrome(string s) {
        int resL=0;
        int l, r;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            //odd length palindrome
            l=i;
            r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>resL){
                    resL = r-l+1;
                    ans = s.substr(l, resL);
                }
                l--;
                r++;
            }

            //even length palindrome
            l = i; 
            r = i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>resL){
                    resL = r-l+1;
                    ans = s.substr(l, resL);
                }
                l--;
                r++;
            }
            
        }
        return ans;
    }
};
