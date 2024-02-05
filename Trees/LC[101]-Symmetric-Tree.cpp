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
   bool isSymmtericHelp(TreeNode* leftNode , TreeNode* rightNode)
   {
       // base case 
        if(leftNode==NULL || rightNode ==NULL) return leftNode== rightNode;

        // check left and right val 
        if(leftNode->val != rightNode->val) return false;
        
        //check both childs of each node 
        return (isSymmtericHelp(leftNode->left,rightNode->right) and isSymmtericHelp(leftNode->right,rightNode->left));
   }    
    bool isSymmetric(TreeNode* root) 
    {
        return (root==NULL || isSymmtericHelp(root->left,root->right));
    }
};