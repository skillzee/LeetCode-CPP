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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        if(root == NULL){
            return ans;
        }
        bool flag = true; //This is for right to left insertion;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            vector<int> v(size);
            for(int i = 0; i<size; i++){
                TreeNode* temp = qu.front();
                qu.pop();

                int index = flag?i:(size-1-i);
                v[index] = temp->val;
                if(temp->left){
                    qu.push(temp->left);
                }
                if(temp->right){
                    qu.push(temp->right);
                }
            }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};