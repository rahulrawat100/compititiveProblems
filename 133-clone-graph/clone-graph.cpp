/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> D;
    Node* cloneGraph(Node* node) {
        if(node==NULL)
           return NULL;
        if(D.find(node->val)!=D.end())
            return D[node->val];
        else    
        {
            Node* root = new Node();
            root->val = node->val;
            D[root->val]=root;
            for(int i=0; i<node->neighbors.size(); i++)
            {
              root->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
            return root;
        }  
    }
};