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
    TreeNode* constructBST(vector<int>&preorder, int mini, int maxi, int &i){
        if(i>=preorder.size()){
            return NULL;
        }
        if(preorder[i]<mini || preorder[i]>maxi){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = constructBST(preorder, mini, root->val, i);
        root->right = constructBST(preorder, root->val, maxi, i);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN, maxi = INT_MAX, i = 0;
        return constructBST(preorder, mini, maxi, i);
    }
};

// Time: O(n)
// Space: O(n)
