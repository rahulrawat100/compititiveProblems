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
    void bfs(queue<TreeNode*>& q, int tot)
    {
        if(q.empty())
           return;
        else
        {
            int t=q.size();
            int currtot=0;
            while(t-->0)
            {
                TreeNode* curr = q.front();
                q.pop();
                int sib=0;
                if(curr->left!=NULL)
                {
                    currtot+=curr->left->val;
                    q.push(curr->left);
                    sib+=curr->left->val;
                       
                }
                if(curr->right!=NULL)
                {
                    currtot+=curr->right->val;
                    q.push(curr->right);
                    sib+=curr->right->val;
                }
                if(curr->right!=NULL)
                   curr->right->val=-sib;
                if(curr->left!=NULL)
                   curr->left->val=-sib;      
                curr->val+=tot;
            }
            bfs(q, currtot);
        }   
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        root->val=0;
        bfs(q, root->val);
        return root;
    }
};