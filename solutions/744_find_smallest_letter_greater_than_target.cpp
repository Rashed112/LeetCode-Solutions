class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0, r=letters.size(), m;
        if(letters.back()<= target) return letters.front();
        while(l<r){
            m=l+(r-l)/2;
            if(letters[m]<=target){
                l=m+1;
            }
            else{
                r=m;
            }
        }
        return letters[l];
        //return letters[l%letters.size()];
    }
};
