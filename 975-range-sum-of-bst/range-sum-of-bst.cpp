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
    int calc(TreeNode* root, int low, int high)
    {
        if(root==NULL)
         return 0;
        else
        {
            if(root->val<low)
               return calc(root->right, low, high);
            else if(root->val>high)
               return calc(root->left, low, high);
            else
            {
                return root->val+calc(root->left, low, high)+calc(root->right, low, high);
            }      

        } 
    }

    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return calc(root, low, high);
    }
};