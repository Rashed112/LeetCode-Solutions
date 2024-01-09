// Approach -1 : Using Sorting for Keys
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> >mp;

        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        vector<vector<string>> res;
        for(auto x:mp){
            res.push_back(x.second);
        }
        return res;
    }
};
// Time: O(n*klog(k))
// Space: O(n*k)

// Apporach - 2: Using Map for Keys
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string> >mp;
        
        for(auto x: strs){
            map<char, int> temp;
            for(auto c: x){
                temp[c]++;
            }
            mp[temp].push_back(x);
        }

        vector<vector<string>>res;
        for(auto x : mp){
            res.push_back(x.second);
        }

        return res;

    }
};
// Time: O(n*k)
// Space: O(n*k)
