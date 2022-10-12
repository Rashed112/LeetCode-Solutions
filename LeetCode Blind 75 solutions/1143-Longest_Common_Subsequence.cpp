class Solution {
public:
    int dp[1005][1005];
    int lcs(int i, int j, string &s1, string &s2){//passing both string as references so that there won't be another copy
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    //remove 1 char from s1
    int ans = lcs(i-1, j, s1, s2);
    //remove 1 char from s2
    ans = max(ans, lcs(i, j-1, s1, s2));
    //remove 1 char from s1 and s2
    ans = max(ans, lcs(i-1, j-1, s1, s2)+(s1[i] == s2[j])); //here if s1[i] equals s2[j], 1 will be added
    return dp[i][j] = ans;
    }
    //TC: O(N^2), cause in dp if it is dp[m][n], then tc is O(m*n), cause recursion will run m*n times
    int longestCommonSubsequence(string text1, string text2) {
    memset(dp, -1, sizeof(dp));
    return lcs(text1.size()-1, text2.size()-1, text1, text2);

    }
};
