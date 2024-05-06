class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, n=people.size();
        sort(people.begin(), people.end());
        int i=0, j=n-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                res++;
                i++;
                j--;
            }
            else{
                res++;
                j--;
            }
        }
        return res;
    }
};
