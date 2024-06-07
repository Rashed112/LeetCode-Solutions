class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int>m;
        for(auto s : dictionary){
            m[s]++;
        }
        string ans="", word;
        sentence+=" ";
        int l = 0, r = 0, f = 0;
        while(r<sentence.size()){
            if(sentence[r]==' '){
                ans += sentence.substr(l, r-l);
                if(r<sentence.size()-1){
                    ans+=" ";
                }
                l=r+1;
            }
            else{
                string root = sentence.substr(l, r-l+1);
                if(m[root]){
                    ans+=root;
                    while(r<sentence.size() && sentence[r]!=' '){
                        r++;
                    }
                    if(r<sentence.size()-1){
                        ans+=" ";
                    }
                    l = r+1;
                }
            }
            r++;
        }
        return ans;
    }
};
