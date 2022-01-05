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
    vector<TreeNode*> h1;
    
    bool findNode(TreeNode *root,TreeNode *a){
        if(root==NULL) return false;
        else if(root==a){
            h1.push_back(root);
            return true;
        }
        else{
            h1.push_back(root);
            if(!findNode(root->left,a)){
               bool f = findNode(root->right,a);
                if(!f){
                    h1.pop_back();
                }
                return f;
            }
            return true;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> h2;
        findNode(root,p);
        h2=h1;
        
        h1.clear();
        findNode(root,q);
        
        int i = 0;
        while(true){
            if(i>h1.size()-1 || i>h2.size()-1 || h1[i]!=h2[i]){
                break;
            }
            i++;
        }
        
        return h1[i-1];
    }
};
