// Approach-1:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<char>s1(s.begin(), s.end()), t1(t.begin(), t.end());
        if(s1.size()!=t1.size()){
            return false;
        }
        unordered_map<char, char>m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()){
                if(m[s[i]] != t[i]){
                    return false;
                }
            }
            m[s[i]] = t[i];
        }
        return true;
    }
};

// Approach-2:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char>m, n;
        for(int i=0;i<s.size();i++){
            int f1 = 0, f2 = 0;
            if(m.find(s[i])!=m.end()){
                if(m[s[i]] != t[i]){
                    f1=1;
                }
            }
            if(n.find(t[i]) != n.end()){
                if(n[t[i]] != s[i]){
                    f2=1;
                }
            }
            if(f1 || f2){
                return false;
            }
            m[s[i]] = t[i];
            n[t[i]] = s[i];
        }
        return true;
    }
};
