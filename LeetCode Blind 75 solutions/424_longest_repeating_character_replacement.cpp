// Solution-1: Intuitive Approach
// Time: O(26*N), Space: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r = 0, maxL=0;
        unordered_map<char, int>ump;
        while(r<s.size()){
            ump[s[r]]++;
            int maxFrequency = 0;
            for(auto x : ump){
                maxFrequency = max(maxFrequency, x.second);
            }
            int windowLength = r-l+1;
            if(windowLength-maxFrequency > k){
                ump[s[l]]--;
                l++;
            }
            maxL = max(maxL, r-l+1);
            r++;
            
        }
        return maxL;
    }
};

// Solution-2: Slightly Optimal Linear Approach
// Time: O(N), Space: O(26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r = 0, maxL=0, maxFrequency=0;
        unordered_map<char, int>ump;
        while(r<s.size()){
            ump[s[r]]++;
            maxFrequency = max(maxFrequency, ump[s[r]]);
            int windowLength = r-l+1;
            if(windowLength-maxFrequency > k){
                ump[s[l]]--;
                l++;
            }
            maxL = max(maxL, r-l+1);
            r++;
        }
        return maxL;
    }
};
