/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void calc(Node* root, vector<Node*>& D, int lev)
    {
        if(root==NULL)
           return;
        else
        {
            if(D.size()>lev)
            {
                D[lev]->next=root;
                D[lev]=root;
            }
            else
            {
                D.push_back(root);
                //root->next=NULL;
            }
            calc(root->left, D, lev+1);
            calc(root->right, D, lev+1);
        }   
    }
    Node* connect(Node* root) {
        vector<Node*> D;
        calc(root, D, 0);
        return root;
    }
};