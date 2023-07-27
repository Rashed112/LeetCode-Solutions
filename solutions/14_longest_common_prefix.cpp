//Solution-1: Brute Force Approach
//Time: O(N^2)
//Space: O(N)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res = "";
        sort(strs.begin(), strs.end());
        string longString = strs[n-1];
        for(int t=0; t<longString.size();t++){
            char temp = longString[t]; 
            for(int i=0;i<strs.size();i++){
                if(strs[i][t] != temp){
                    return res;
                }
            }
            res+=temp;
        }
        return res;
    }
};

//Solution-2: Optimal Approach
//Time: O(N*logN)
//Space: O(N)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res = "";
        sort(strs.begin(), strs.end());
        string smallString = strs[0], largeString = strs[n-1];
        for(int i=0; i<smallString.size();i++){
            if(smallString[i] != largeString[i]){
                return res;
            }
            res+=smallString[i];
        }
        return res;
    }
};
