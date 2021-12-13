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
    int answer;
    int calHeight(TreeNode *root){
        if(root==NULL) return 0;
        else{
            return 1+max(calHeight(root->left),calHeight(root->right));    
        }
    }
    void calSum(TreeNode *root,int localheight,int maxheight){
        if(root==NULL) return;
        else{
            if(root->left == NULL && root->right==NULL && localheight==maxheight) answer+=root->val;
            calSum(root->left,localheight+1,maxheight);
            calSum(root->right,localheight+1,maxheight);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        answer=0;
        int height = calHeight(root);
        calSum(root,1,height);
        return answer;
    }
};
