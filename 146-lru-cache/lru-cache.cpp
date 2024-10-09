class Node
{
    public:
    int val;
    int key;
    Node* next=NULL;
    Node* prev=NULL;
};
class LRUCache {
public:
    int Capacity;
    unordered_map<int, Node*> mp;
    Node* left=NULL;
    Node* right=NULL;
    LRUCache(int capacity) {
        Capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
          return -1;
        Node* curr=mp[key];
        MovetoFrequent(curr);
        return curr->val;
    }
    
    void MovetoFrequent(Node* curr)
    {
        if(curr->next==NULL)
           return;
        else if(curr->prev==NULL)
        {
            curr->next->prev=NULL;
            left=curr->next;
            left->prev=NULL;
            right->next=curr;
            curr->prev=right;
            curr->next=NULL;
            right=curr;
            return;
        }   
        else
        {
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            right->next=curr;
            curr->prev=right;
            curr->next=NULL;
            right=curr;
            return;
        } 
    }

    void put(int key, int value) {
       if(mp.find(key)==mp.end())
       {
            if(mp.size()==Capacity)
            {
                mp.erase(left->key);
                if(mp.size()==0)
                {
                    left=NULL;
                    right=NULL;
                }
                else
                {
                left=left->next;
                left->prev=NULL;
                }
            }
            Node* node = new Node();
            node->key=key;
            node->val=value;
            if(right==NULL&&left==NULL)
               {
                  right=node;
                  left=node;
                  mp[key]=node;
                  return;
               }
            node->prev=right;
            right->next=node;
            right=node;
            mp[key]=node;
       }
       else
       {
           Node* cur = mp[key];
           cur->val=value;
           MovetoFrequent(cur);
       }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */