//Binary Search | TC O(n * log(n))
//very important to understand binary search

class Solution {
public:
    bool canShip(vector<int>& weights, int cap, int days){
        int daysNeeded = 1, currentLoad = 0;
        for(int w: weights){
            currentLoad += w;
            if(currentLoad > cap){
                daysNeeded++;
                currentLoad = w;
            }
        }
        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int totalLoad = 0, maxLoad = 0;
        for(int w : weights){
            totalLoad += w;
            maxLoad = max(maxLoad, w);
        }
        int l = maxLoad, r = totalLoad;
        while(l<r){
            int mid = l + (r-l)/2;
            if(canShip(weights, mid, days)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
