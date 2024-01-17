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
    TreeNode* calc(TreeNode* root)
    {
        if(root==NULL)
           return NULL;
        else
        {
            TreeNode* temp = new TreeNode(root->val);
            temp->left=calc(root->right);
            temp->right=calc(root->left);
            return temp;
        }   
    }
    TreeNode* invertTree(TreeNode* root) {
        return calc(root);
    }
};