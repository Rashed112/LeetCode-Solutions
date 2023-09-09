//Solution-1: With Converting Integer to String
//Time: O(n)
//Space: O(n)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s = to_string(x);
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};

//Solution-2: Without Converting Integer to String
//Time: O(n)
//Space: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0  && x%10==0)){
            return false;
        }
        int sum=0;
        while(x>sum){
            sum = sum*10+x%10;
            x/=10;
        }
        return (x==sum) || (x==sum/10);
    }
};
