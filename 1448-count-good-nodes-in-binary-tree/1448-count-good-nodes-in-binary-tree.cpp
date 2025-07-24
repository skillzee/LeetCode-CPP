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
    int solve(TreeNode* root, int currMax){
        if(root == NULL) return 0;
        int count = (root->val >= currMax) ? 1 : 0;

        
        currMax = max(currMax, root->val);

        int left = 0;
        int right = 0;

        if(root->left){
            left = solve(root->left, currMax);
        }
        if(root->right){
            right = solve(root->right, currMax);
        }

        return count+left+right;
    }

    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int currMax = root->val;

        int count = solve(root, currMax);
        

        return count;
    }
};