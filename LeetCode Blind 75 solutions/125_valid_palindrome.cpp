//SOLUTION-1: Using Two Pointers

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0, r=n-1;
        while(l<r){
            while(l<r && !isalnum(s[l])){
                l++;
            }
            while(l<r && !isalnum(s[r])){
                r--;
            }
            if(tolower(s[l++]) != tolower(s[r--])){
                return false;
            }
        }
        return true;
    }
};


//SOLUTION-2: Brute Force, uses extra space

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]+=32;
            }
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                str+=s[i];
            }
        }
        int i=0, j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
