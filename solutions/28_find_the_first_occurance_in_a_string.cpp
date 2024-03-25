class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(n<m){
            return -1;
        }
        if(m==n && haystack == needle){
            return 0;
        }
        for(int i=0;i<n-m+1;i++){
            string temp = haystack.substr(i, m);
            if(temp == needle){
                return i;
            }
        }
        return -1;
    }
};
