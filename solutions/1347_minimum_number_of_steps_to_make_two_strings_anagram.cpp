class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int>um;
        for(int i=0;i<s.size();i++){
            um[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            um[t[i]]--;   
        }
        int res=0;
        for(auto x: um){
            /*Negative value represent the characters which are there in string t but not in string s.*/
            if(x.second<0){
                res+=abs(x.second);
            }
        }            
        return res;
    }
};
