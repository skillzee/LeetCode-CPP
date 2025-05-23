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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maximum(root, maxi);
        return maxi;
        
    }

    int maximum(TreeNode* root, int& maxi){
        if(root == NULL){
            return 0;
        }
        int leftMax = max(0, maximum(root->left, maxi));
        int rightMax = max(0, maximum(root->right, maxi));
        maxi = max(maxi, root->val+leftMax+rightMax);
        return root->val + max(leftMax, rightMax);

    }
};