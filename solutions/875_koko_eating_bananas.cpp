//very important binary search problem
//TC O(n logM)

class Solution {
    #define ll long long
public:
    ll minEatingSpeed(vector<int>& piles, int h) {
        ll res = INT_MAX, l = 1, r = *max_element(piles.begin(), piles.end());
        while(l<=r){
            ll mid = l+(r-l)/2;
            ll hours =0;
            for(int p : piles){
                hours += ceil(p/(double)mid); 
            }
            if(hours<=h){
                res = min(res, mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
            
        }
        return res ;
    }
};
