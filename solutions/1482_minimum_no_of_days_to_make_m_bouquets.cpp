class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m>bloomDay.size()/k){
            return -1;
        }
        int n = bloomDay.size();
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(l<=r){
            int mid = l+(r-l)/2;
            int count = 0, b=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    count++;
                }
                else{
                    b+=count/k;
                    count=0;
                }
            }
            b += count/k;
            if(b<m){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return r+1;
    }
};

// Time: O(nlogD) where n = no of flowers, D = difference between max and min value of bloomDay
// Space: O(1)
