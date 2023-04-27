//important stack problem

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        unordered_map<int, int>ump;
        stack<int>st;
        vector<int>res(n1,-1);
        for(int i=0;i<n1;i++){
            ump[nums1[i]]=i;
        }
        for(int i=0;i<n2;i++){
            while(!st.empty() && nums2[i]>st.top()){
                res[ump[st.top()]]=nums2[i];
                st.pop();
            }
            if(ump.find(nums2[i])!=ump.end()){
                st.push(nums2[i]);
            }
            
        }
        return res;
    }
};
