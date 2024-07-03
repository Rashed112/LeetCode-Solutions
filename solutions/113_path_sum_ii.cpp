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
    void findPaths(TreeNode* root, int currSum, int targetSum, vector<int>&path, vector<vector<int>>&paths){
        if(!root){
            return;
        }
        currSum += root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && currSum == targetSum){
            paths.push_back(path);
        }
        findPaths(root->left, currSum, targetSum, path, paths);
        findPaths(root->right, currSum, targetSum, path, paths);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        vector<int>path;
        findPaths(root, 0, targetSum, path, paths);
        return paths;
    }
};
