class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>ransom, mag;
        for(int i=0;i<ransomNote.size();i++){
            ransom[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            mag[magazine[i]]++;
        }
        for(auto c : ransom){
            if(mag[c.first] < c.second){
                return false;
            }
        }
        return true;
    }
};
