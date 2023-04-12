class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s1;
        unordered_map<char, int>s2;
        for(int i=0;i<s.size();i++){
            s1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            s2[t[i]]++;
        }
        int f=0;
        for(auto c: t){
            if(s1[c]!=s2[c]){
                f=1;
            }
        }
        if(f==0 && s.size()==t.size()) return true;
        else return false;
    }
};
