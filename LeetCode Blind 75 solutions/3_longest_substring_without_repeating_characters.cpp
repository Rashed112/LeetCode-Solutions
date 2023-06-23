class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>uset;
        int r=0, l=0, maxi=0;
        while(r<s.size()){
            while(uset.find(s[r]) != uset.end()){
                uset.erase(s[l]);
                l++;
            }
            uset.insert(s[r]);
            r++;
            maxi = max(maxi, r-l);
        }
        return maxi;
    }
};

// Time : O(n)
// Space : O(n)
// Sliding window + Set
