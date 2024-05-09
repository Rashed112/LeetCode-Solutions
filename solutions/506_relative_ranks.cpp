class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>res(score.size());
        vector<int>temp(score.begin(), score.end());
        unordered_map<int, int>m;
        sort(temp.rbegin(), temp.rend());
        for(int i=0;i<temp.size();i++){
            
            m[temp[i]]=i+1;
        }
        for(int i=0;i<score.size();i++){
            if(m[score[i]]==1){
                res[i]="Gold Medal";
            }
            else if(m[score[i]]==2){
                res[i]="Silver Medal";
            }
            else if(m[score[i]]==3){
                res[i]="Bronze Medal";
            }
            else{

                res[i]=to_string(m[score[i]]);
            }
        }

        return res;
    }
};
