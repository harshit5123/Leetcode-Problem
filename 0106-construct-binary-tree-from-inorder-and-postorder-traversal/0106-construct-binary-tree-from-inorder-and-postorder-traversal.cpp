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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode*root=buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>&inorder,int instart,int inend, vector<int>&postorder,int postart ,int poend ,map<int,int>&mpp){
        if(instart>inend || postart>poend) return NULL;
        TreeNode* root= new TreeNode(postorder[poend]);
        int rootidx=mpp[root->val];
        int leftpos=rootidx-instart;
        root->left=buildTree(inorder,instart,rootidx-1,postorder,postart,postart+leftpos-1,mpp);
        root->right=buildTree(inorder,rootidx+1,inend,postorder,postart+leftpos,poend-1,mpp);
        return root;

    }
};