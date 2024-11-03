class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        if(s==goal){
            return true;
        }
        int n = s.size()-1;

        while(n--){
            char ch = s[0];
            s.erase(0,1);
            s+=ch;
            if(s == goal){
                return true;
            }          
        }
        return false;
    }
};
