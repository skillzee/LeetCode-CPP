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

     void in(TreeNode* root, int k, vector<int>& predOrder){
        if(root == NULL){
            return;
        }

       in(root->left,k,predOrder);
       predOrder.push_back(root->val);
       
       in(root->right, k, predOrder);
    }

    bool findTarget(TreeNode* root, int target) {
        vector<int>v;
        in(root, target, v);
        for(auto it: v){
            cout<<it<<" ";
        }



    vector<int> ans;
    unordered_map<int, int> mp;

    for(int i = 0; i < v.size(); i++)
    {

        int comp = target - v[i];
        if(mp.find(comp)!=mp.end()){
            ans.push_back(mp[comp]+1);
            ans.push_back(i+1);
            return true;
        }
        mp[v[i]] = i;
    }

    return false;
    }
};