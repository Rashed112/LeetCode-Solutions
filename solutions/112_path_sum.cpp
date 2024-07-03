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
    bool sumCheck(TreeNode* root, int currSum, int targetSum){
        if(root == NULL){
            return false;
        }
        currSum += root->val;
        if(!root->left && !root->right){
            return currSum == targetSum;
        }

        bool left = sumCheck(root->left, currSum, targetSum);
        bool right = sumCheck(root->right, currSum, targetSum);
        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return sumCheck(root, 0, targetSum);
    }
};
