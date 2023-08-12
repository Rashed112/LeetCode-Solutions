class Solution {
public:
    vector<string>valid;
    void generate(string &s, int open, int close){
        //cout<<s<<endl;
        if(open==0 && close==0){
            valid.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            generate(s, open-1, close);
            s.pop_back(); /*for backtracking, basically returning the string s to it's previous parent node state so that it doesn't effect the next child node*/
        }
        if(close>0){
            if(open<close){
                s.push_back(')');
                generate(s, open, close-1);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s, n, n);
        return valid;
    }
};

/*
- Time complexity:
O(2^N) where N = 2*n
We have N = 2*n places to fill and for every place we will have a maximum of 2 choices. 
Since recursion is a tree, and here there are two recursive calls possible at any level. 
Heigh of the tree will be 2*n, since we are generating 2*n number of brackets.

- Space complexity:
O(N) (Stack space after using recursion), where N = 2*n
*/
