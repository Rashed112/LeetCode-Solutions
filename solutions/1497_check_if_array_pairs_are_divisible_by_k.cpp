class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int>m;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            m[(arr[i]%k+k)%k]++; // handling the negative numbers
        }
        if(m[0]%2==1){
            return false;
        }
        for(int i=1; i<k; i++){
           if(m[i]!=m[k-i]){
            return false;
           }
        }
        return true;
    }
};
