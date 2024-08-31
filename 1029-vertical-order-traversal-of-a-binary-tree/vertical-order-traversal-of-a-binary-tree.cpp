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
    map<int, map<int, multiset<int>>> D;
    void calc(TreeNode* root, int i, int j)
    {
        if(root==NULL)
          return;
        else
        {
            D[j][i].insert(root->val);
            calc(root->left, i+1, j-1);
            calc(root->right, i+1, j+1);
        }  
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
         calc(root, 0, 0);
        for(auto it: D)
        {
            vector<int> t;
            for(auto jt:it.second)
            {
               for(auto kt:jt.second)
               {
                  t.push_back(kt);
               }
            }
            res.push_back(t);
        }
        return res;
    }
};