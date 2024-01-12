class Node
{
    public:
    int l;
    int r;
    int val;
    Node* left=NULL;
    Node* right=NULL;
};

Node* create(vector<int>& nums, int i, int j)
{
    //cout<<i<<" "<<j<<endl;
    if(i>j)
      return NULL;
     if(i==j)
     {
         Node* n= new Node();
         n->l=i;
         n->r=j;
         n->val=nums[i];
         return n;
     }
    else
    {
        int mid = i+(j-i)/2;
        Node* n= new Node();
        n->left = create(nums, i, mid);
        n->right = create(nums, mid+1, j);
        n->val = n->left->val+n->right->val;
        n->l=i;
        n->r=j;
        return n;
    } 
}


int calcsum(Node* root, int i, int j)
{
    if(root->l>=i&&root->r<=j)
       return root->val;
     else if(root->r<i || root->l>j)
      return 0;
     else
      return calcsum(root->left, i, j)+calcsum(root->right, i, j);      
}

void updates(Node* root, int i, int value)
{
    if(root->r<i ||root->l>i)
      return;
    if(root->l==i && root->r==i)
      {
          root->val=value;
      }
     else 
     {
          updates(root->left, i, value);
          updates(root->right, i, value);
          root->val = root->left->val+root->right->val;
     }
}
class NumArray {
public:
    Node* root;
    NumArray(vector<int>& nums) {
       root =create(nums, 0, nums.size()-1);  
    }
    
    void update(int index, int val) {
        updates(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return calcsum(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */