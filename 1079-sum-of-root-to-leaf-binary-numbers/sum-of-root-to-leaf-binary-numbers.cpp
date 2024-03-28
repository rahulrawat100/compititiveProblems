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
    int calc(TreeNode* root, int x)
    {

        if(root->left==NULL&& root->right==NULL)
        {
            x=x<<1;
            if(root->val==1)
              x++;
           return x;
        }
        else
        {
            int y = x;
            y=y<<1;
            if(root->val==1)
              y++;
              int sum=0;
            if(root->left!=NULL)  
            sum+=calc(root->left, y);
            if(root->right!=NULL)
            sum+=calc(root->right, y);
            return sum;  
        }   

    }
    int sumRootToLeaf(TreeNode* root) {
        return calc(root, 0);
    }
};