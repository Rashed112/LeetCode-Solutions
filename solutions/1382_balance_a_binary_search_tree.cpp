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
    TreeNode* inorderToBST(int s, int e, vector<int>inorder){
        if(s>e){
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode *root = new TreeNode(inorder[mid]);
        root->left = inorderToBST(s, mid-1, inorder);
        root->right = inorderToBST(mid+1, e, inorder);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        // step-1: get the sorted list (using inorder traversal)
        TreeNode* curr = root;
        stack<TreeNode*>st;
        vector<int>v;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode *temp = st.top();
            st.pop();
            v.push_back(temp->val);
            curr = temp->right;
        }
        // step-2: get the mid 
        int mid = v.size()/2;
        // step-3: make the balanced bst
        return inorderToBST(0, v.size()-1, v);
    }
};

// Time: O(n)
// Space: O(n)
