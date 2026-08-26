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
    int findleftheight(TreeNode*node){
        int lhs=0;
        while(node){
            lhs++;
            node=node->left;
        }
        return lhs;
    }
    int findrightheight(TreeNode*node){
        int rhs=0;
        while(node){
            rhs++;
            node=node->right;
        }
        return rhs;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=findleftheight(root);
        int rh=findrightheight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};