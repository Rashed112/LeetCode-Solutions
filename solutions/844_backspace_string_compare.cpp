//Method-1: Using Stack
//Time: O(N)
//Space: O(N)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1, s2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(s[i]);
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                s2.push(t[i]);
            }
        }
        if(s1==s2){
            return true;
        }
        else{
            return false;
        }
    }
};


//Method-2: Using Two Pointers
//Time: O(N)
//Space: O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int p=0, q=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                p--;
                p=max(0, p);
            }
            else{
                s[p]=s[i];
                p++;
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                q--;
                q = max(0, q);
            }
            else{
                t[q]=t[i];
                q++;
            }
        }
        if(p!=q){
            return false;
        }
        else{
            for(int i=0;i<p;i++){
                if(s[i]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
