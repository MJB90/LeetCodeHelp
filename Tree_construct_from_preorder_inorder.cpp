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
    int preIndex;
    TreeNode *build(vector<int>& preorder, vector<int>& inorder,int start,int end){
        if(start>end) return NULL;
        
        TreeNode *tnode = new TreeNode(preorder[preIndex++]);
        
        if(start==end) return tnode;
        
        auto it = find(inorder.begin(),inorder.end(),tnode->val);
        int inIndex = it-inorder.begin();
        
        tnode->left = build(preorder,inorder,start,inIndex-1);
        tnode->right= build(preorder,inorder,inIndex+1,end);
        return tnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;
        return build(preorder,inorder,0,preorder.size()-1);
    }
};
