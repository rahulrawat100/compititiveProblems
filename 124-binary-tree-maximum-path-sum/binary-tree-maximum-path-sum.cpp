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
    int calc(TreeNode* root, int& res)
    {
       if(root==NULL)
          return 0;
        else
        {
            int left =calc(root->left, res);
            int right = calc(root->right, res);
            res=max(res, root->val+left+right);
            res=max(res, root->val+left);
            res=max(res, root->val+right);
            res=max(res, root->val);
            return root->val+max(0, max(left, right));
        } 
    }
    int maxPathSum(TreeNode* root) {
          int res=INT_MIN;
          calc(root, res);
          return res;

    }
};