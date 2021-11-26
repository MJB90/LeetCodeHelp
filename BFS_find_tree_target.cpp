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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> oq,cq;
        oq.push(original);
        cq.push(cloned);
        
        while(!oq.empty()){
            TreeNode *ot = oq.front();
            oq.pop();
            TreeNode *ct = cq.front();
            cq.pop();
            if(ot==target) return ct;
            else{
                if(ot->left!=NULL){
                    oq.push(ot->left);
                    cq.push(ct->left);
                }
                
                if(ot->right!=NULL){
                    oq.push(ot->right);
                    cq.push(ct->right);
                }
            }
            
        }
        return NULL;
    }
};
