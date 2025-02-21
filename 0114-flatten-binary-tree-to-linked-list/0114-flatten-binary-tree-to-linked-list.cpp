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
    void trav(TreeNode* root, vector<TreeNode*> &preOrder){
        if(root == NULL){
            return;
        }
        preOrder.push_back(root);
        // cout<<root->val;
        trav(root->left, preOrder);
        trav(root->right, preOrder);
    }

    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        vector<TreeNode*> preOrder;
        trav(root, preOrder);
        for(auto it: preOrder){
            cout<<it->val<<" ";
        }

        for (int i = 0; i < preOrder.size() - 1; i++) {
            preOrder[i]->left = NULL;
            preOrder[i]->right = preOrder[i + 1];
        }

    }
};