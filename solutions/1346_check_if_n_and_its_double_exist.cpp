class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
         unordered_map<int, int>ump;
         int n=arr.size();
         
         for(int i=0;i<n;i++){
             if(ump.find(arr[i]*2)!=ump.end() || (arr[i]%2==0 && ump.find(arr[i]/2)!=ump.end())){
                 return true;
             }
             ump[arr[i]]++;
         }
         return false;
    }
};
