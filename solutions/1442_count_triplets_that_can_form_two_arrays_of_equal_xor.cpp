class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0, curr_xor = 0, n=arr.size();
        for(int i=0;i<n;i++){
            curr_xor = arr[i];
            for(int j=i+1;j<n;j++){
                curr_xor ^= arr[j];
                if(curr_xor == 0){
                    res += j-i;
                }
            }
        }
        return res;
    }
};
