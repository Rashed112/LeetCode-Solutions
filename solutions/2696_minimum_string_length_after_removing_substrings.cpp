class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char curr = s[i];
            if(st.empty()){
                st.push(curr);
                continue;
            }

            if(curr == 'B' && st.top()=='A'){
                st.pop();
            }
            else if(curr == 'D' && st.top() == 'C'){
                st.pop();
            }
            else{
                st.push(curr);
            }
        }
        return st.size();
    }
};
