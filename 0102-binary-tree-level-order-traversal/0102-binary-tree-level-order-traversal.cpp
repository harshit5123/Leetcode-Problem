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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*>qs;
        qs.push(root);
        while(!qs.empty()){
            int size=qs.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                root=qs.front();
                qs.pop();
                level.push_back(root->val);
            if(root->left) qs.push(root->left);
            if(root->right) qs.push(root->right);
            }
            ans.push_back(level);
        }
    return ans;
    }
};