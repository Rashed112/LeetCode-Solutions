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
    void preorder(TreeNode* root, string &res){
        if(root == NULL){
            return;
        }
        res += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            return;
        }

        res.push_back('(');
        preorder(root->left, res);
        res.push_back(')');

        if(root->right){
            res.push_back('(');
        }
        preorder(root->right, res);
        if(root->right){
            res.push_back(')');
        }
    }

    string tree2str(TreeNode* root) {
        string res;
        preorder(root, res);
        return res;
    }
};

// Time: O(n), preorder traversal
// Space: O(n), result string size
