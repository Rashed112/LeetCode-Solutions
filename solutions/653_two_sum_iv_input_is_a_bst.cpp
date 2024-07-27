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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int>m;
        TreeNode *curr = root;
        stack<TreeNode*>st;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode *node = st.top();
            if(m[k-node->val]){
                return true;
            }
            m[node->val]++;
            st.pop();
            curr = node->right;
        }
        return false;
    }
};
