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
 #include<bits/stdc++.h>
 
class Solution {
public:
    int findSmallestPos(vector<int>& nums,int l,int h){
        int maxVal = nums[l];
        int pos = l;
        while(l<=h){
            if(nums[l]>maxVal){
                maxVal=nums[l];
                pos=l;
            }
            l++;
        }
        return pos;
    }
    TreeNode* constructHelper(vector<int>& nums,int l,int h){
        if(l>h) return NULL;
        TreeNode* temp;
        int maxPos = findSmallestPos(nums,l,h);
        temp = new TreeNode(nums[maxPos]);
        temp->left = constructHelper(nums,l,maxPos-1);
        temp->right = constructHelper(nums,maxPos+1,h);
        return temp;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
     return constructHelper(nums,0,nums.size()-1);   
    }
};
