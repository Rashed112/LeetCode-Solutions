class Solution {
public:
    int captureForts(vector<int>& forts) {
        int f=0, maxi=0;
        vector<int>v;
        for(int i=0;i<forts.size();i++){
            if(forts[i]==1 || forts[i]==-1){
                v.push_back(i);
                //if(forts[i]==1) f=1;
            }
            
        }
        for(int i=1;i<v.size();i++){
            if(forts[v[i-1]] != forts[v[i]]){
                maxi=max(maxi, v[i]-v[i-1]);
            }
                
            
        }
        if( maxi>1)
            return maxi-1;
        else 
            return 0;
    }
};
