class Solution {
public:
    string compressedString(string word) {
        string comp="";
        for(int i=0;i<word.size();){
            char ch = word[i];
            int cnt = 0;
            while(i<word.size()){
                if(cnt==9){
                    break;
                }
                if(word[i]==ch){
                    i++;
                    cnt++;
                }
                else{
                    break;
                }
            }
            comp+=to_string(cnt)+ch;
        }
        return comp;
    }
};
