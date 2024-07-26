/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode* curr = root;
        vector<int>v;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode *node = st.top();
            v.push_back(node->val);
            st.pop();
            curr = node->right;
        }
        sort(v.begin(), v.end());
        long long int smallest = v[0];
        for(auto x : v){
            if(x>smallest){
                return x;
            }
        }
        return -1;
    }
};
