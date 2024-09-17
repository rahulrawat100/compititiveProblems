class Node
{
    public:
    Node* child[26];
};

class Solution {
public:
    
    Node* root;
    
    void Add(string& word)
    {
        Node* temp=root;
        int n = word.size();
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(temp->child[ind]==NULL)
                temp->child[ind]=new Node();
            temp=temp->child[ind];
        }
    }
    
    long long calc(string& target, int i, Node* node, vector<long long>& DP)
    {
        if(i==target.size())
            return 1;
        else
        {
            int ind=target[i]-'a';
            long long res=INT_MAX;
           if(node->child[ind]!=NULL) 
            res=min(res, calc(target, i+1, node->child[ind], DP));
            if(root->child[ind]!=NULL)
            {
                if(DP[i]==-1)
                DP[i]=1+calc(target, i+1, root->child[ind], DP);
                res=min(res, DP[i]);
            }
            return res;
        }
    }
    int minValidStrings(vector<string>& words, string target) {
        int m=words.size();
        root=new Node();
        
        for(int i=0; i<m; i++)
        {
            Add(words[i]);
        }
        int n = target.size();
        vector<long long> DP(n, -1);
        int res= calc(target, 0, root, DP);
        return res==INT_MAX?-1:res;
    }
};