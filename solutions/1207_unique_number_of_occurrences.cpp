class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int> ump;
        set<int>s;
        for(int i=0;i<n;i++){
            ump[arr[i]]++;
        }
        for(auto i : ump){
            s.insert(i.second);
        }
        return ump.size()==s.size();
    }
};
