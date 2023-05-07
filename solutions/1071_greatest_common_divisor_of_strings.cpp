class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string str="";
        int n = str1.size(), m=str2.size();
        if(str1+str2 != str2+str1) //O(m+n)
        {
            return "";
        }
        int ansLength = gcd(n, m); // O(log(m.n))
        return str1.substr(0, ansLength);
    }
    //So ultimately TC O(m+n)
    //and also SC O(m+n)
};
