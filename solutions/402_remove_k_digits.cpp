class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size(), cnt = k;
        stack<char>st;
        for(int i=0;i<n;i++){
            while(cnt>0 && !st.empty() && st.top()>num[i]){
                st.pop();
                cnt--;
            }
            st.push(num[i]);
        }
        while(st.size() > n-k){
            st.pop();
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        while(res[0] == '0'){
            res.erase(0, 1);
        }
        return res==""? "0": res;
    }
};
