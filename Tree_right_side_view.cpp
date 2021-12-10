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
    map<int,int> answer;
    void helper(TreeNode* root,int height){
        if(root==NULL) return;
        else{
            if(answer.find(height)==answer.end()){
                answer[height]=root->val;
            }
            helper(root->right,height+1);
            helper(root->left,height+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        answer.clear();
        helper(root,0);
        
        vector<int> toReturn;
        for(auto it:answer){
            toReturn.push_back(it.second);
        }
        return toReturn;
    }
};
