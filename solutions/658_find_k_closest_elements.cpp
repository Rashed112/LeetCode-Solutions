class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, r=arr.size()-k;
        //finding the window of k closest elements
        while(l<r){
            int m = l+(r-l)/2;
            //it can also be seen as checking x > (arr[m+k]+arr[m])/2
            /*don't check it with abs() as it prevents handling the edge cases where arr[mid]==arr[mid+k], cause if we have minus values we can also keep index-wise*/ 
            if(x-arr[m]>arr[m+k]-x){
                l = m+1;
            }
            else{
                r=m;
            }
        }
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};

//Time: O(log(N-K)+K)
//Space: O(K) to create the returned list.
