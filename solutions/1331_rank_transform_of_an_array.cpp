class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()<1){
            return {};
        }
        vector<int>v(arr.begin(), arr.end());
        sort(v.begin(), v.end());
        unordered_map<int,int>m;
        m[v[0]]=1;
        for(int i=1;i<v.size();i++){
            if(v[i]>v[i-1]){
                m[v[i]]=m[v[i-1]]+1;
            }
            else{
                m[v[i]]=m[v[i-1]];
            }
        }
        
        for(int i=0;i<arr.size();i++){
            arr[i]=m[arr[i]];
        }
        return arr;
    }
};
