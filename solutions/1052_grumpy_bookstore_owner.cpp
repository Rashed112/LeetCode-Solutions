class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0, r = 0;
        int maxWindow = 0, window = 0, satisfied=0;
        while(r<customers.size()){
            if(grumpy[r]){
                window+=customers[r];
            }
            else{
                satisfied+=customers[r];
            }
            if(r-l+1>minutes){
                if(grumpy[l]){
                    window-=customers[l];
                }
                l++;
            }
            r++;
            maxWindow = max(maxWindow, window);
        }
        return maxWindow+satisfied;
    }
};
