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
    int ans;
    int depth(TreeNode* root)
    {
        if(root==NULL)
         return 0;
        else
        {
            int left = depth(root->left);
            int right = depth(root->right);
            ans=max(ans, left+right+1);
            return 1+max(left, right);
        } 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        depth(root);
        return ans-1;
    }
};