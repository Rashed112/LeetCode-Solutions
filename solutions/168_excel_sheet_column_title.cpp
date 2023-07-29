class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber){
            columnNumber--;
            res += (char)(columnNumber%26 + 'A');
            columnNumber/=26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
Time complexity: O(log⁡N)
The number of operations would be equal to the number of while loops iterations. 
In each iteration, the number N gets divided by 26. Hence the time complexity would be O(log⁡26N).
Note that the base of the logarithm is not relevant when it comes to big O, since all logarithms are related by a constant factor.

Space complexity: O(1)
We only need one string to store the output, but generally, the space to store the output is not considered part of space complexity
and hence the space complexity is constant.
*/
