class Solution {
public:
    bool isCircularSentence(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && s[i-1]!=s[i+1]){
                return false;
            }
        }
        return s[0] == s[s.size()-1];
    }
};
