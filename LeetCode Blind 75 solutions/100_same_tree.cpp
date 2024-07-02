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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q==NULL && p==NULL){
            return true;
        }
        if((q==NULL && p!=NULL) ||(q!=NULL && p==NULL)){
            return false;
        }
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool isEqual = p->val == q->val;
        if(left && right && isEqual){
            return true;
        }
        return false;
    }
};
