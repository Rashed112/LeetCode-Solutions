class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3 ){
            return false;
        }
        set<char>v={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        bool res = true, con = false, vow = false;
        for(int i=0;i<word.size();i++){
            if(!isalnum(word[i])){
                return false;
            }
            
            if(v.find(word[i]) != v.end()){
                con = true;
            }
            else if(isalpha(word[i])){
                vow = true;
            }
            
        }
        
        return res & con & vow;
    }
};
