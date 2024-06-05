class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int>m1;
        for(auto ch : words[0]){
            m1[ch]++;
        }
        vector<string>res;
        
        for(int i=1;i<n;i++){
            unordered_map<char, int>m2;
            for(auto ch : words[i]){
                m2[ch]++;
            }
            for (auto it = m1.begin(); it != m1.end(); ) {
                if (m2.find(it->first) == m2.end()) {
                    it = m1.erase(it);
                } else {
                    it->second = min(it->second, m2[it->first]);
                    it++;
                }
            }
        }
        for(auto x : m1){
            string s = "";
            s+=x.first;
            for(int i=0;i<x.second;i++){
                res.push_back(s);
            }
        }
        return res;
    }
};

// Time: O(n*k)
// Space: O(1)
