class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int res=0, f=0;
        for(auto x: m){
            if(x.second%2==0){
                res+=x.second;
            }
            else{
                f=1;
                res+=x.second-1;
            }
        }
        return res+f;
    }
};
