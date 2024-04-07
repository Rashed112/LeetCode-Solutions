class Solution {
public:
    bool checkValidString(string s) {
        stack<int>openBrackets, asterisks;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                openBrackets.push(i);
            }
            else if(s[i]=='*'){
                asterisks.push(i);
            }
            else{
                if(!openBrackets.empty()){
                    openBrackets.pop();
                }
                else if(!asterisks.empty()){
                    asterisks.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!openBrackets.empty() && !asterisks.empty()){
            if(openBrackets.top()>asterisks.top()){
                return false;
            }
            openBrackets.pop();
            asterisks.pop();
        }
        return openBrackets.empty();
    }
};
