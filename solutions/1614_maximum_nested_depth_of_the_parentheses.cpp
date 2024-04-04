class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cnt =0;
        for(auto ch : s){
            if(ch == '('){
                cnt++;
            }
            else if(ch == ')'){
                cnt--;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
