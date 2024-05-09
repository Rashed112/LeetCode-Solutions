class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        unordered_map<char, int> m;
        for(auto ch : t){
            m[ch]++;
        }
        int l = 0, r = 0, res = 0, count = m.size(), len=INT_MAX;
        while(r<s.size()){
            m[s[r]]--;
            if(m[s[r]]==0){
                count--;
            }
            
            while(count == 0){
                if(len > r-l+1){
                    len = r-l+1;
                    res = l;
                }
                m[s[l]]++;
                if(m[s[l]]>0){
                    count++;
                }
                l++;
            }
            r++;
        }
        return len==INT_MAX? "": s.substr(res, len);
    }
};

// Time: O(n)
// Space: O(n)
