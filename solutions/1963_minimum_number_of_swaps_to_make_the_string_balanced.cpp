class Solution {
public:
    int minSwaps(string s) {
        int extraCB = 0, res = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                extraCB++;
                res = max(res, extraCB);
            }
            else{
                extraCB--;
            }
        }
        return (res+1)/2; // as one swap balance out 2 closing brackets
    }
};
