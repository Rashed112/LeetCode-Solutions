class Solution {
public:
    int countPrimes(int n) {
        vector<long long int>primes(n);
        int cnt=0;
        for(long long int i=2;i<n;i++){
            if(primes[i]==0){
                cnt++;
                for(long long int j=i*i;j<n;j+=i){
                    primes[j]=1;
                }
            }
            primes[i]^=1;

        }
        return cnt;
    }
};
