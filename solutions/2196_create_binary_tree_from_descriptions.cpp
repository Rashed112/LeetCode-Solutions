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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> s;
        for(int i=0;i<descriptions.size();i++){
            s.insert(descriptions[i][1]);
        }
        unordered_map<int, TreeNode*>m;
        TreeNode *head = NULL, *parent = NULL, *child = NULL;
        for(int i=0;i<descriptions.size();i++){
            
            if(!m[descriptions[i][0]]){
                parent = new TreeNode(descriptions[i][0]);
                m[descriptions[i][0]] = parent;
            }
            else{
                parent = m[descriptions[i][0]];
            }
            if(!m[descriptions[i][1]]){
                child = new TreeNode(descriptions[i][1]);
                m[descriptions[i][1]] = child;
            }
            else{
                child = m[descriptions[i][1]];
            }
            if(descriptions[i][2] == 1){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
            if(s.find(descriptions[i][0]) == s.end()){
                head = m[descriptions[i][0]];
            }

        }
        return head;

    }
};
