class Solution {
public:
    string makeFancyString(string s) {
        int l=0;
        string res="";
        
        while(l<s.size()){
            if(res.size()>=2 && res[res.size()-1]== s[l] && res[res.size()-2]==s[l]){
                l++;
                continue;
            }
            else{
                res+=s[l];
                l++;
            }
        }
        return res;
    }
};
