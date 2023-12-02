class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        unordered_map<char, int>ump, temp;
        for(auto ch: chars){
            ump[ch]++;
        }
        for(auto word: words){
            int f=0;
            temp = ump;
            for(auto ch : word){
                if(!temp[ch]){
                    f=1;
                    break;
                }
                else{
                    temp[ch]--;
                }
            }
            if(!f){
                res+=word.size();
            }
        }
        return res;
    }
};

// Time : O(N * M), N = number of words, M = average length of a word
// Space : O(1), as here the highest size of the unordered_map is constant which is 26, the total number of alphabets
