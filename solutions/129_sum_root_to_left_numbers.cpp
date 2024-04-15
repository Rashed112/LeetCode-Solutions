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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int cur){
        if(!root) return 0;
        cur = cur*10 + root->val;
        if(!root->left && !root->right){
            return cur;
        }
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
};


// Time: O(N)
// Space: O(H), where H is the maximum depth of tree. This space is required for implicit recursive stack space. 
// In the worst case, the tree maybe skewed and H = N in which case space required is equal to O(N)
