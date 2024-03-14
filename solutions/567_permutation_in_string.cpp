class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int l = 0, r = 0;
        if(m> n){
            return false;
        }
        vector<int>freqS1(26, 0), freqS2(26, 0);
        for(int i=0;i<m;i++){
            freqS1[s1[i]-'a']++;
            freqS2[s2[i]-'a']++;
        }
        if(freqS1 == freqS2){
            return true;
        }
        for(int i=m;i<n;i++){
            r = i;
            l = i-m;
            freqS2[s2[r]-'a']++;
            freqS2[s2[l]-'a']--;
            if(freqS1 == freqS2){
                return true;
            }
        }
        return false;
    }
};

// Time: O(n)
// Space: O(1)
