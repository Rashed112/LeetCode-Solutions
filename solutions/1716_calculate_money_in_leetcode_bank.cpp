class Solution {
public:
    int totalMoney(int n) {
        vector<int>v{0, 1, 3, 6, 10, 15, 21};
        int weeks = n/7, days = n%7, res = 0, weekSum=0;
        for(int i=1;i<=weeks;i++){
            weekSum+=(3+i)*7;
        }
        res = weekSum + weeks*days+v[days];
        return res;
    }
};
