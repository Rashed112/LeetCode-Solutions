//Solution-1: [Using Linear Search]
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0, n=1, skip=0, l=arr.size();
        while(i<l){
            if(arr[i] != n){
                skip++;
                if(skip==k) return n;
                n++;
            }
            else{
                i++;
                n++;
            }
        }
        return arr[l-1]+(k-skip);
    }
};


//Solution-2: [Using Binary Search]
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0, r=arr.size(); //cause missing num could be out of bound
        while(l<r){
            int m = l+(r-l)/2;
            if(arr[m]-(m+1) < k){
                l=m+1;
            }
            else{
                r=m; //for upper bound pos
            }
        }
        return l+k;
        
    }
};
