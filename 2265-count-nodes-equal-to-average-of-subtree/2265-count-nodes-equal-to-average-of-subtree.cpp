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
 int findsum(TreeNode*root,int &count){
    if(root==NULL) return 0;
    count++;
    int ls=findsum(root->left,count);
    int rs=findsum(root->right,count);
    return ls+rs+root->val;

 }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int count=0;
        int sum=findsum(root,count);
        int ans=0;
        if(root->val==sum/count) ans++;
        ans+=averageOfSubtree(root->left);
        ans+=averageOfSubtree(root->right); 
        return ans;
    }
};