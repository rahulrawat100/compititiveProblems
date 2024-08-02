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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& root, int l, int r)
    {
        if(l>r)
           return NULL;
        if(root>=preorder.size())
           return NULL;
       int x = preorder[root];
       int j;
       for(j=l; j<=r; j++)
       {
           if(inorder[j]==x)
              break;
       }
       TreeNode* rt = new TreeNode(x);
       root++;
       rt->left = build(preorder, inorder, root, l, j-1);
       rt->right = build(preorder, inorder, root, j+1, r);
       return rt;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root=0;
        return build(preorder, inorder, root, 0, inorder.size()-1);
    }
};