class Solution {
public:
    bool isValid(string s) {
        stack<char>ch;
        int n = s.size();
        unordered_map<char, char>mp = { {')', '('}, {'}', '{'}, {']', '['}};
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{'|| s[i]=='['){
                ch.push(s[i]);
            }
            else{
                if(ch.empty() || ch.top() != mp[s[i]]){
                    return false;
                }
                ch.pop();
            }
        }
        return ch.empty();
    }
};
