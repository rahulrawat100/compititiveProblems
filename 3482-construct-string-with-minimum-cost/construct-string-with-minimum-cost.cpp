class Node
{
    public:
    Node* child[26];
    int cost=-1;
};

class Solution {
public:
    Node* trie=new Node();
    
    void insert(string& word, int Cost)
    {
        Node* temp = trie;
        
        for(int i=0; i<word.size();i++)
        {
            int ind = word[i]-'a';
            if(temp->child[ind]==NULL)
                temp->child[ind] = new Node();
            temp = temp->child[ind];
        }
        if(temp->cost==-1)
           temp->cost = Cost;
        else
           temp->cost=min(temp->cost, Cost);   
    }
    
    long long calc(Node* curr, string& target, int i, vector<int>& DP)
    {
        if(i==target.size())
        {
            if(curr->cost==-1)
               return INT_MAX;
            return curr->cost;
        }
        else if(curr==trie&&DP[i]!=-1)
          return DP[i]; 
        else
        {
            long long res=INT_MAX;
            if(curr->cost!=-1)
                res=min(res, curr->cost+calc(trie, target, i, DP));
            int ind = target[i]-'a';
            if(curr->child[ind]!=NULL)
                res=min(res, calc(curr->child[ind], target, i+1, DP));
            if(curr == trie)
               DP[i]=res;
            return res;
        }
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = words.size();
        int m = target.size();
        vector<int> DP(m, -1);
        for(int i=0; i<n; i++)
        {
          insert(words[i], costs[i]);
        }
        
        int res= calc(trie, target, 0, DP);
        return res>=INT_MAX?-1:res;
    }
};