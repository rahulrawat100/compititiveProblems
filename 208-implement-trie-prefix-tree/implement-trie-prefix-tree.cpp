class Node
{
    public:
    Node* child[26];
    bool end=false;
};
class Trie {
public:
    Node* node;
    Trie() {
        node = new Node();
    }
    
    void insert(string word) {
        int n =word.size();
        Node* temp=node;
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(temp->child[ind]==NULL)
              temp->child[ind]=new Node();
            temp=temp->child[ind];   
        }
        temp->end=true;
    }
    
    bool search(string word) {
        int n =word.size();
        Node* temp=node;
        for(int i=0; i<n; i++)
        {
            int ind = word[i]-'a';
            if(temp->child[ind]==NULL)
              return false;
            temp=temp->child[ind];   
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        int n =prefix.size();
        Node* temp=node;
        for(int i=0; i<n; i++)
        {
            int ind = prefix[i]-'a';
            if(temp->child[ind]==NULL)
              return false;
            temp=temp->child[ind];   
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */