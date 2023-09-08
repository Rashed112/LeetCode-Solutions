class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>ump = {{'I', 1},{'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && ump[s[i+1]]>ump[s[i]]){
                res-=ump[s[i]];
            }
            else{
                res+=ump[s[i]];
            }
        }
        return res;
    }
};

//Time: O(N)
//Space: O(1), as the map size is always fixed and if we take a long size of string, it would be negligible.
