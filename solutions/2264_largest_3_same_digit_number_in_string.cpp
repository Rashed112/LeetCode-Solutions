class Solution {
public:
    string largestGoodInteger(string num) {
        int maxN = -1, idx;
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                if(num[i]-'0'>maxN){
                    idx=i;
                }
                maxN = max(maxN, num[i]-'0');
            }
        }
        
        return (maxN==-1 ? "": num.substr(idx, 3));
    }
};
