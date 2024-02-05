#include<bits/stdc++.h>
using namespace std;
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
   
    bool validateBST(TreeNode* root , long long int  low , long long int high)
    {
        if(root== NULL) return true;

        // check 
        if( (low!= LONG_MIN && root->val<=low) || (high!= LONG_MAX && root->val>=high) )
        {
            return false;
        }

        // else check left and right subtree
        return ( validateBST(root->left, low , root->val)  &&  validateBST(root->right,root->val,high) );
    }

    bool isValidBST(TreeNode* root) {
        
        // Approach 1: using inorder traversal to check whether array will be in sorted order or not 

        // Approach 2 : using low , high technique 
        return validateBST(root,LONG_MIN,LONG_MAX);
    }
};