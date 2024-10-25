class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string>res;
        unordered_set<string>h, k;
        for(auto s : folder){
            h.insert(s);
        }
        for(int i=0;i<n;i++){
            string s = folder[i];            
            for(int j = 1; j<s.size();j++){
                if(s[j]=='/'){
                    if(h.find(s.substr(0, j))!=h.end()){
                        k.insert(s.substr(0, j));
                        break;
                    }                    
                }
                if(j==s.size()-1){
                    k.insert(s);
                }
            }
        }
        for(auto s : k){
            res.push_back(s);
        }
        return res;
    }
};
