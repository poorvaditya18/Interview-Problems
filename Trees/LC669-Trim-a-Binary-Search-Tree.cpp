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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        // in both cases discard the subtree
        // if value of node is less than low then its subtree will also have value less than low
        // if value of node is grter than high then its subtree will also have value grter than high 

        // base case 
        if(root==NULL) return root;

        if(root->val < low) 
        {
            return trimBST(root->right,low,high);
        }
        else if(root->val > high)
        {
            return trimBST(root->left,low,high);
        }

        // attach to root what will be returned from left subtree and right subtree
        root->left = trimBST(root->left,low,high);

        root->right = trimBST(root->right,low,high);

        return root;

    }
};