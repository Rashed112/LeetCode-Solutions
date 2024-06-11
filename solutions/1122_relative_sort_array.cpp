class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxElement = *max_element(arr1.begin(), arr1.end());
        vector<int>count(maxElement+1);
        for(auto x : arr1){
            count[x]++;
        }
        vector<int>res;
        for(auto x : arr2){
            while(count[x]){
                res.push_back(x);
                count[x]--;
            }
        }
        for(int i=0;i<=maxElement; i++){
            while(count[i]){
                res.push_back(i);
                count[i]--;
            }
        }
        return res;
    }
};
