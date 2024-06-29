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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int>level;
            for(int i=0;i<len;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                level.push_back(temp->val);
            }
            res.push_back(level);
        }
        for(int i=0;i<res.size()/2;i++){
            swap(res[i], res[res.size()-1-i]);
        }
        return res;
    }
};
