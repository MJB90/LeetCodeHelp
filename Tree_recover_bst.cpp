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
    void getPreorder(TreeNode *root,vector<int> &preorder){
        if(root==NULL) return;
        else{
            getPreorder(root->left,preorder);
            preorder.push_back(root->val);
            getPreorder(root->right,preorder);
        }
    }
    
    void replaceTree(TreeNode *root,vector<int> &replace){
        if(root==NULL) return;
        else{
            if(root->val == replace[0]) root->val = replace[1];
            else if(root->val == replace[1]) root->val = replace[0];
            
            replaceTree(root->left,replace);
            replaceTree(root->right,replace);
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> preorder;
        getPreorder(root,preorder);
        vector<int> sortedOrder = preorder;
        sort(sortedOrder.begin(),sortedOrder.end());
        
        vector<int> replace;
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]!=sortedOrder[i]){
                replace.push_back(preorder[i]);
            }
        }
        
        replaceTree(root,replace);
    }
};
