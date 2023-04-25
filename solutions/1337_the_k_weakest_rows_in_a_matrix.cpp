class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        set<pair<int, int>>sp;
        for(int i=0;i<n;i++){
            int x= count(mat[i].begin(), mat[i].end(), 1);
            sp.insert({x, i});
        }
        int i=0;
        vector<int>res;
        for(auto m: sp){
            if(i<k){
                res.push_back(m.second);
                i++;
            }
            else break;
        }
        return res;

    }
};
