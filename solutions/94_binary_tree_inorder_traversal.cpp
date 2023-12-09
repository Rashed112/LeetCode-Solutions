// Approach-1: Recursive Solution
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
    void inorder(TreeNode* root, vector<int>&res){
        if(root == NULL){
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        inorder(root, res);
        return res;
    }
};
// Time: O(n)
// Space: O(n)

// Approach-1: Iterative Solution
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        TreeNode* curr = root;

        while(curr!= NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* node = st.top();
            res.push_back(node->val);
            st.pop();
            curr = node->right;
        }
        return res;
    }
};
// Time: O(n)
// Space: O(n)
