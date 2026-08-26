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
    int findmaxdistance(map<TreeNode*,TreeNode*>&mpp,TreeNode* target){
        queue<TreeNode*>qs;
        map<TreeNode*,int> vis;
        qs.push(target);
        vis[target]=1;
        int maxi=0;
        while(!qs.empty()){
               int sz=qs.size();
               int flag=0;
               for(int i=0;i<sz;i++){
                auto node=qs.front();
                qs.pop();
                if(node->left && !vis[node->left]){
                    flag=1;
                    vis[node->left]=1;
                    qs.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    flag=1;
                    vis[node->right]=1;
                    qs.push(node->right);
                }
                if(mpp[node] && !vis[mpp[node]]){
                    flag=1;
                    vis[mpp[node]]=1;
                    qs.push(mpp[node]);
                }
               }
               if(flag) maxi++;
        }
        return maxi;
    }
    TreeNode*tobfsparents(TreeNode*root,map<TreeNode*,TreeNode*>&mpp,int target){
        queue<TreeNode*>qs;
        qs.push(root);
        TreeNode* res;
        while(!qs.empty()){
            TreeNode*node=qs.front();
            if(node->val==target) res=node;
            qs.pop();
            if(node->left){
                mpp[node->left]=node;
                qs.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                qs.push(node->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mpp;
        TreeNode* target=tobfsparents(root,mpp,start);
        int maxi=findmaxdistance(mpp,target);
        return maxi;
    }
};