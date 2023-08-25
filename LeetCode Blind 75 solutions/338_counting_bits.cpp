//Solution-1:
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;i++){
            res.push_back(__builtin_popcount(i));
        }
        return res;
    }
};

//Solution-2:
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1);
        res[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                res[i] = res[i/2]; /*as for every even num bits no remains same as the (num/2) number*/
            }
            else{
                res[i]=res[i-1]+1;
            }
        }
        return res;
    }
};
