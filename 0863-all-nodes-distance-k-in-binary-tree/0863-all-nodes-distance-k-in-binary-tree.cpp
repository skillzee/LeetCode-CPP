/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void makeGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>> &mp){
        if(root == NULL){
            return;
        }
        if (root->left) {
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
            makeGraph(root->left, mp);
        }
        if (root->right) {
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
            makeGraph(root->right, mp);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // What I am thinking is to make a graph from the tree. Lets see if that works (This is approach 1)
        unordered_map<TreeNode*, vector<TreeNode*>> mp;


        if(root == NULL || target == NULL){
            return {};
        }

        if(k == 0){
            return {target->val};
        }

        makeGraph(root, mp);


        queue<pair<TreeNode*, int>> q;

        q.push({target, 0});
        vector<int> ans;
        // cout<<mp.size()<<endl;
        set<TreeNode*> visited;

        while(!q.empty()){
            TreeNode* node = q.front().first;
            visited.insert(node);
            int dist = q.front().second;
            q.pop();
            for(auto it: mp[node]){
                if(!visited.count(it)){
                    if(dist+1 == k){
                        ans.push_back(it->val);
                    }
                    q.push({it, dist+1});

                }
            }
        }

        return ans;

        
    }
};