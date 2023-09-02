class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int f=0;
        for(int i=0;i<2;i++){
            if(s1[i]==s2[i] || s1[i]==s2[i+2]){
                continue;
            }
            else{
                f=1;
            }
        }
        for(int i=3;i>1;i--){
            if(s1[i]==s2[i] || s1[i]==s2[i-2]){
                continue;
            }
            else{
                f=1;
            }
        }
        return f==1? false : true;
    }
};
