// Approach-1:
class Solution {
public:
    string makeGood(string s) {
        string res = "";
        
        for(int i=0;i<s.size();i++){
            res+=s[i];
            while(res.size() && (res.back()==s[i+1]+32 || res.back()==s[i+1]-32)){
                res.pop_back();
                i++;
            }
        }

        return res;
    }
};

// Approach-2:
class Solution {
public:
    string makeGood(string s) {
        string res = "";
        
        if(s.size()<2) {
            return s;
        }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && abs(st.top()-s[i])==('a'-'A')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
