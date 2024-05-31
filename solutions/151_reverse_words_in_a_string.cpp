// Solution - 1 :
class Solution {
public:
    string reverseWords(string s) {
       vector<string>v;
       string res="", word="";
       int n = s.size();
       for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(word.size()){
                    v.push_back(word);
                    word="";
                }
            }
            else{
                word+=s[i];
            }
       }
       if(word.size()){

            v.push_back(word);
       }
       
       for(int i=v.size()-1;i>=0; i--){
            res+=v[i];
            if(i>0){
                res+=" ";
            }
       }
       return res; 
    }
};

// Solution - 2:
class Solution {
public:
    string reverseWords(string s) {
        int i = s.size()-1;
        string res="";
        while(i>=0){
            while(i>=0 && s[i]==' '){
                i--;
            }
            int end = i;
            while(i>=0 && s[i]!=' '){
                i--;
            }
            int start = i+1;
            res+=s.substr(start, end-start+1)+" ";
        }
        while(!res.empty() && res[res.size()-1]==' '){
            res.erase(res.begin()+res.size()-1);
        }
        return res;
    }
};
