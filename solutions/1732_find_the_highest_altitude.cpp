class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(), maxN = 0, sum =0;
        for(int i =0; i<n;i++){
            sum += gain[i];
            maxN = max(maxN, sum);
        }
        return maxN;
    }
};
