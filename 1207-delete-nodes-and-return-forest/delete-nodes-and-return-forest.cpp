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
    TreeNode* calc(TreeNode* root, unordered_set<int>& del, vector<TreeNode*>& res, bool deleted)
    {
        if(root==NULL)
          return NULL;
        else
        {
            if(del.find(root->val)!=del.end())
            {
                calc(root->left, del, res, true);
                calc(root->right, del, res, true);
                return NULL;
            }
            else
            {
                if(deleted)
                  res.push_back(root);
                root->left = calc(root->left, del, res, false);
                root->right = calc(root->right, del, res, false);
                return root;  
            }
        }   
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> D;
        for(int i=0; i<to_delete.size(); i++)
        {
            D.insert(to_delete[i]);
        }
        vector<TreeNode*> res;
        calc(root, D, res, true);
        return res;
    }
};