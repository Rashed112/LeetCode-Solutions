class Solution {
public:
    bool isValid(int x, vector<int>&position, int m){
        int count = 1, prev = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-prev>=x){
                count++;
                prev = position[i];
            }
        }
        return count>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int l = 1; // as at least there should be gap of 1
        int r = ceil(position[n-1] / (m-1.0)); // highest possible gap
        int res = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isValid(mid, position, m)){
                res = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        } 
        return res;
    }
};
