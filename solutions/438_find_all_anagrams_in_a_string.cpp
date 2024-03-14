class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int>res;
        if(m<n){
            return res;
        }
        vector<int> freqS(26, 0), freqP(26, 0);

        for(int i = 0; i<n; i++){
            freqP[p[i]-'a']++;
            freqS[s[i]-'a']++;
        }
        if( freqP == freqS){
            res.push_back(0);
        }
        
        for(int i = n; i<m; i++){
            int r = i, l = i-n;
            freqS[s[r]-'a']++;
            freqS[s[l]-'a']--;

            if(freqS == freqP){
                res.push_back(l+1);
            }
        }
        return res;
    }
};

// Time: O(n)
// Space: O(1)
