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
    TreeNode* calc(unordered_map<int, int>& pre, vector<int>& preorder, int l, int r, int& ind)
    {
        if(ind==preorder.size() || l>r )
           return NULL;
        else
        {
            int pos=pre[preorder[ind]];
            TreeNode* root = new TreeNode();
            root->val=preorder[ind];
            ind++;
            root->left=calc(pre, preorder, l, pos-1, ind);
            root->right=calc(pre, preorder, pos+1, r, ind);
             return root;
        }   
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int ind=0;
        unordered_map<int, int> pre;
        for(int i=0; i<n; i++)
        {
            pre[inorder[i]]=i;
        }
        return calc(pre, preorder, 0, n-1, ind);
    }
};