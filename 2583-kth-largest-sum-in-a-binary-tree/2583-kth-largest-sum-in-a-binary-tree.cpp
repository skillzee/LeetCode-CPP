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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // vector<long long> sums;
        vector<pair<TreeNode*, int>> test;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        // int level = 1;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            test.push_back({node, level});
            if(node->left){
                q.push({node->left, level+1});
            }
            if(node->right){
                q.push({node->right, level+1});
            }
            // TreeNode* testNode = new TreeNode(0);
            // test.push_back(testNode);
        }
        map<int, long long> mp; 
        for (auto it : test) {
            mp[it.second] += it.first->val; 
        }

        vector<long long> sums;
        for (auto it : mp) {
            sums.push_back(it.second); 
        }

        
        sort(sums.begin(), sums.end(), greater<long long>());


        if (k > sums.size()) return -1;
        
        return sums[k - 1];
    }
};