class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<char>v1, v2, v3, v4;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                v2.push_back(s1[i-1]);
                v4.push_back(s2[i-1]);
            }
            else{
                v1.push_back(s1[i-1]);
                v3.push_back(s2[i-1]);
            }
            
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());
        if(v1!=v3 || v2!=v4){
            return false;
        }
        return true;   
    }
};
