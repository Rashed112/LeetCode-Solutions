class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        unordered_map<char, string> m={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        string curr = "";
        vector<string>res;

        dfs(digits, 0, m, curr, res);
        return res;
    }
private:
    void dfs(string digits, int index, unordered_map<char, string>&m, string &curr, vector<string>&res){
        if(index == digits.size()){
            res.push_back(curr);
            return;
        }
        string str = m[digits[index]];
        for(int i =0;i<str.size();i++){
            curr.push_back(str[i]);
            dfs(digits, index+1, m, curr, res);
            curr.pop_back();
        }
    }
};

//Time: O(4^n)
//Space: O(n)
