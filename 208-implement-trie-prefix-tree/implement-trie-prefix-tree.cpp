class Node
{
   public:
     bool ends=false;
     Node* child[26];
};

class Trie {
public:
    Node* root = new Node();
    Trie() {
        
    }
    
    void insert(string word) {
        Node* curr =root;
        for(int i=0; i<word.size(); i++)
        {
            int ind = word[i]-'a';
            if(curr->child[ind]==NULL)
               curr->child[ind]=new Node();
            curr=curr->child[ind];   
        }
        curr->ends=true;
    }
    
    bool search(string word) {
        Node* curr =root;
        for(int i=0; i<word.size(); i++)
        {
            int ind = word[i]-'a';
                        cout<<ind<<endl;
            if(curr->child[ind]==NULL)
               return false;
            curr=curr->child[ind];   
        }
        return curr->ends;
    }
    
    bool startsWith(string prefix) {
                Node* curr =root;
        for(int i=0; i<prefix.size(); i++)
        {
            int ind = prefix[i]-'a';
            if(curr->child[ind]==NULL)
               return false;
            curr=curr->child[ind];   
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