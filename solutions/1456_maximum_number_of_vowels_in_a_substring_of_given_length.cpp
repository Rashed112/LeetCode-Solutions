//hints: substring = sliding window problem

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char>vowels{'a', 'e', 'i', 'o', 'u'};
        int cnt = 0, n=s.size();
        for(int i=0;i<k;i++){
            cnt+=vowels.count(s[i]);
        }
        int res = cnt;

        for(int i=k; i<n;i++){
            cnt+=vowels.count(s[i])-vowels.count(s[i-k]);
            res = max(res, cnt);
        }
        return res;
    }
};
