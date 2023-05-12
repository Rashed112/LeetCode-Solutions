//Solution-1:
class Solution {
public:
    string reverseVowels(string s) {
        int l=0, r = s.size()-1;
        
        while(l<r){
            bool left=false, right=false;
            if((s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u' || s[l]=='A' || s[l]=='E' || s[l]=='I' || s[l]=='O' || s[l]=='U') ){
                left = true;
            }
            if((s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u' || s[r]=='A' || s[r]=='E' || s[r]=='I' || s[r]=='O' || s[r]=='U') ){
                right = true;
            }
            if(left && right){
                swap(s[l], s[r]);
                l++; 
                r--;
            }
            if(left == false){
                l++;
            }
            if(right == false){
                r--;
            }
            
        }
        return s;
    }
};

//Solution-2:
class Solution {
public:
    string reverseVowels(string s) {
        int l=0, r = s.size()-1;
        set<char>vowels={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(l<r){
           while(l<r && !vowels.count(s[l])) l++;
           while(l<r && !vowels.count(s[r])) r--;
           swap(s[l++], s[r--]);
        }
        return s;
    }
};
