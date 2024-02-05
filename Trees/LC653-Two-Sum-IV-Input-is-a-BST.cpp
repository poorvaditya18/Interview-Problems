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
    set<int> st;
    bool findTarget(TreeNode* root, int k) {
        // base case 
        if(root==NULL)
        {
            return false;
        }
        
        //check in set 
        if(st.find(k-root->val)!=st.end())
        {
            return true;
        }

        // add element 
        st.insert(root->val);

        return (findTarget(root->left,k) || findTarget(root->right,k));
    }
};