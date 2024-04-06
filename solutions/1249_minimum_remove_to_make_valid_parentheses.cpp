class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }
            if(cnt<0){
                cnt=0;
                
            }
            else{
                res+=s[i];
            }
        }
        
        for(int i=res.size()-1;i>=0;i--){
            if(cnt==0){
                break;
            }
            if(res[i]=='('){
                res.erase(i,1);
                cnt--;
            }
        }
        
        return res;
    }
};
