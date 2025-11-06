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
    int maxDist = 0;

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxDist;
    }


    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftPath = 0, rightPath = 0;

        if(root->left and root->left->val == root->val){
            leftPath = left+1;
        }

        if(root->right and root->right->val == root->val){
            rightPath = right+1;
        }

        maxDist = max(maxDist, leftPath+rightPath);

        return max(leftPath, rightPath);
    }
};